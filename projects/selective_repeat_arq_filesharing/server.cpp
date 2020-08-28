#include "server.h" // includes server declarations

using namespace std;

/*
*Construnctor* of SR_ARQ_Server
Calls when the object is created
*/
SR_ARQ_Server::SR_ARQ_Server(): logger("logs.log", ofstream::out | ofstream::app){
    // open the file to write
    this->openFile();
}

/*
Method to open the file to write the data 
that is coming
*/
void SR_ARQ_Server::openFile(){
    // open the file named "out.txt" in write byte format
    this->outputFilePtr = fopen(OUT_FILENAME, "w");
    // if the file not found throw the error
    if(this->outputFilePtr == NULL){
        this->die("openFile()");
    }
}

/*
Method to close the file.
*/
void SR_ARQ_Server::closeFile(){
    fclose(this->outputFilePtr);
}

/*
Helper method to show the error and exit the program
*/
void SR_ARQ_Server::die(string s){
    perror(s.c_str());
    exit(1);
}  

string SR_ARQ_Server::currentDateTime() {
   char            fmt[64], buf[64];
   struct timeval  tv;
   struct tm       *tm;
   gettimeofday(&tv, NULL);
   tm = localtime(&tv.tv_sec);
   strftime(fmt, sizeof fmt, "%H:%M:%S.%%06u", tm);
   snprintf(buf, sizeof buf, fmt, tv.tv_usec);
   return buf;
}

void SR_ARQ_Server::logit(
    string event, 
    string packettype,
    string src, 
    string dest, 
    string seqNo
){
    this->logger << "SERVER" << setw(5) << event << "    " 
    << currentDateTime() << setw(9) << packettype << setw(5) << seqNo <<
    "    " << src << setw(9) << dest <<  setw(5) << endl;
}

/*
Method to initialize the server
*/
void SR_ARQ_Server::connectSocket(){
    this->sock_fd=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP); 
    if (sock_fd== -1){
        die("socket");
    }
    memset((char *) &si_me, 0, sizeof(si_me));
    this->si_me.sin_family = AF_INET;
    this->si_me.sin_port = htons(SERVERPORT);
    this->si_me.sin_addr.s_addr = htonl(INADDR_ANY);

    //bind socket to port
    if( bind(this->sock_fd, 
        (struct sockaddr*)&si_me, sizeof(si_me) ) == -1){
        die("bind");
    }

}

/*
 Helper method that decode the string to integer
 For example,
 "0053" => 53 
 "1254" => 1254
*/
int SR_ARQ_Server::decodeStringToInt(char* str, int valBytes){
    int val = 0;
    int i = 0;
    while(str[i] == '0' && i < valBytes){
        i++;
    }
    for(int j = i; j < valBytes; j++){
        val = val*10 + (str[j] - '0');
    }
    return val;
}

/*
Decode the buffer which is been recieved
The format of Buffer is
<seq_no><pkt_length><is_last_pkt><pkt_type><payload>
where seq_no, pkt_length, is_last_pkt, pkt_type are of 4 chars each,
and payload is the remaining character in packet.
For example
Suppose the packet is: "0001025000010000My name is Jai"
In this,
seq_no = 0001 == 1,
pkt_length = 0250 == 250,
is_last_pkt == 0001 == 1: Yes,
pkt_type === 0000 == 0: Data packet.
*/
int* SR_ARQ_Server::decodeMessage(char* msg){
    int totalVal = 4;
    int valBytes = 4;
    int j = 0;
    int* valueArr = new int[totalVal];
    while(j < totalVal){
        char dat[valBytes+1];
        int i = 0;
        while(i < valBytes){
            dat[i] = msg[j*valBytes + i];
            i++;
        }
        dat[i] = '\0';
        int val = this->decodeStringToInt(dat, valBytes);
        valueArr[j] = val;
        j++;
    }
    return valueArr;
}

/*
Create the string in the format
<seq_no><pkt_length><is_last_pkt><pkt_type>
where seq_no, pkt_length, is_last_pkt, pkt_type are of 4 chars each,
*/
string SR_ARQ_Server::encryptACKPacket(Packet* newPacket){
    string message = this->encodeIntToString(newPacket->seq_no) + // 4
        this-> encodeIntToString(newPacket->pkt_length) + // 4
        this-> encodeIntToString(newPacket->is_last_pkt) + // 4
        this-> encodeIntToString(newPacket->pkt_type) ; // 4
    return message;
}

/*
 Helper method that encode the string to integer
 For example,
 53 => "0053" 
 1254 => "1254"
*/
string SR_ARQ_Server::encodeIntToString(int numb){
    string strNumb;
    int i = ENCODE_LIMIT;
    while(numb != 0){
        strNumb.push_back('0' + numb%10);
        numb = numb/10;
        i--;
    }
    while(i--)
        strNumb.push_back('0');
    reverse(strNumb.begin(), strNumb.end());
    return strNumb;
}

/*
Method that create a Packet STructure and
then returns back the packet
*/
Packet* SR_ARQ_Server::createACKPacket(int ackNo){
    Packet* newPacket = new Packet;
    newPacket->is_last_pkt = 0;
    newPacket->pkt_type = ACK_PACKET;
    newPacket->seq_no = ackNo;
    newPacket->payload = "";
    newPacket->pkt_length = 0; // + NO PAYLOAD
    return newPacket;
}

/*
**Important Method of the class**
*/

void SR_ARQ_Server::send(){
    fd_set select_fds;                /* fd's used by select */
    struct timeval timeout;           /* Time value for time out */
       /* Timeout set for 5 sec + 0 micro sec*/
    int totalWindPktRcvd = 0;
    int recv_len;
    char buffer[BUFLEN];
    int is_last_pack = 0; // Stores the last packet or not info
    int ack_no; // stores the ack no to be send
    bool is_started = false;
    bool isTimeout = false;
    int lastWinAck = -1;

    cout << "Server started" << endl;
    while(1){
        fflush(stdout);

        totalWindPktRcvd = 0;

        for(int i = 0; i < WINDOW_SIZE; i++)
            this->recvWin[i] = -1;

        while(totalWindPktRcvd < WINDOW_SIZE){

            FD_ZERO(&select_fds);             /* Clear out fd's */
            FD_SET(this->sock_fd, &select_fds);           /* Set the bit that corresponds to SOCKET*/
            timeout.tv_sec = SERVER_TIMEOUT;  
            

            if (is_started && select(32, &select_fds, NULL, NULL, &timeout) == 0 ){
                isTimeout = true;
                break;
            }

            is_started = true;
            
            if (
                (recv_len = recvfrom(
                    this->sock_fd,
                    buffer, // stores the data in buffer
                    BUFLEN,
                    0,
                    (struct sockaddr *) &si_other, 
                    &this->slen)) == -1){
                die("recvfrom()");
            }
            // Get the HEADER from the string
            int* valArray = decodeMessage(buffer);

            ack_no = valArray[0];
            
            string RELAYNAME;
            if (ack_no%2 == 0) RELAYNAME = "RELAY" + to_string(2);
            else RELAYNAME = "RELAY" + to_string(1);

            this->logit("R", "DATA", RELAYNAME, "SERVER", to_string(ack_no));

            // create a new ACK packet with ack_no
            Packet* newACKPacket = this->createACKPacket(ack_no);
            // encrypt the packet
            string newBUFF = this->encryptACKPacket(newACKPacket);
            // send the ACK packet
            this->logit("S", "ACK", "SERVER", RELAYNAME, to_string(ack_no));
            if (
                sendto(
                    this->sock_fd,
                    newBUFF.c_str(),
                    newBUFF.length(),
                    0,
                    (struct sockaddr*) &si_other, this->slen
                ) == -1){
                die("sendto()");
            }
            // payload is after HEADER

            if(this->recvWin[ack_no%WINDOW_SIZE] == -1 && ack_no > lastWinAck){
                totalWindPktRcvd++;
                this->recvWin[ack_no%WINDOW_SIZE] = ack_no;
                this->recieverBuffer[ack_no%WINDOW_SIZE] = buffer + HEADERLEN;
            }
            // else{
                // cout << "DUP Packet:" << ack_no << endl; 
            // }
        } // end while

        lastWinAck = this->recvWin[WINDOW_SIZE-1];

        // cout << "Writing buffer to file" << endl;
        for(int i = 0; i < WINDOW_SIZE; i++){
            if(this->recvWin[i] != -1){
                strcpy(buffer, this->recieverBuffer[i].c_str());
                fprintf(this->outputFilePtr, "%s", buffer);
            }
            this->recieverBuffer[i] = "";
        }

        if(isTimeout){
            cout << "SERVER TIMEOUT" << endl;
            cout << "CLOSING SERVER CONNECTION" << endl;
            this->closeSocket();
            this->closeFile();
            this->logger << endl; 
            this -> logger << "-----------------------------------------------------------------" << endl;
            this->logger << endl << endl;
            break;
        }

    } // end while
}

/*----- Closing the socket -----*/
void SR_ARQ_Server::closeSocket(){
    close(this->sock_fd); 
}


// Driver code 
int main() { 
    // create the object og GBNServer
    SR_ARQ_Server serverInstance = SR_ARQ_Server();
    // create serevr
    serverInstance.connectSocket();
    // send the process of sending and recieveing
    serverInstance.send();
    return 0; 
} 
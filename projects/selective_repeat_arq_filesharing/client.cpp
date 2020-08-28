#include "client.h"

using namespace std;

/*
*Construnctor* of SR_ARQ_Client
Calls when the object is created
*/    
SR_ARQ_Client::SR_ARQ_Client(): logger("logs.log", ofstream::out | ofstream::app){
    this->seqNo = 0;
    this->openFile(INPUT_FILENAME);
}

/*
Helper method to show the error and exit the program
*/
void SR_ARQ_Client::die(string s){
    perror(s.c_str());
    exit(1);
}

/*
Method to initialize the Client socket
*/
void SR_ARQ_Client::connectSocket(){
    /////////// Creating connection for 2nd relay//////////////////
    this->sock_fd2=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (this->sock_fd2 == -1){
        this->die("socket");
    }
    memset((char *) &rs1_saddr, 0, sizeof(rs2_saddr));
    rs2_saddr.sin_family = AF_INET;
    rs2_saddr.sin_port = htons(RELAYPORT2);
    rs2_saddr.sin_addr.s_addr = inet_addr(RELAYIP2);

    /////////// Creating connection for 1nd relay//////////////////
    this->sockfd_rs1=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (this->sockfd_rs1 == -1){
        this->die("socket");
    }
    memset((char *) &rs1_saddr, 0, sizeof(rs1_saddr));
    rs1_saddr.sin_family = AF_INET;
    rs1_saddr.sin_port = htons(RELAYPORT1);
    rs1_saddr.sin_addr.s_addr = inet_addr(RELAYIP1);
}

string SR_ARQ_Client::currentDateTime() {
   char            fmt[64], buf[64];
   struct timeval  tv;
   struct tm       *tm;
   gettimeofday(&tv, NULL);
   tm = localtime(&tv.tv_sec);
   strftime(fmt, sizeof fmt, "%H:%M:%S.%%06u", tm);
   snprintf(buf, sizeof buf, fmt, tv.tv_usec);
   return buf;
}

void SR_ARQ_Client::logit(
    string event, 
    string packettype,
    string src, 
    string dest, 
    string seqNo
){
    this->logger << "CLIENT" << setw(5) << event << "    " 
    << currentDateTime() << setw(9) << packettype << setw(5) << seqNo <<
    "    " << src << setw(9) << dest <<  setw(5) << endl;
}

/*
Method to open the file to read the data 
*/
void SR_ARQ_Client::openFile(const char* fileName){
    /*----- Opening the output file -----*/
    this->inputFilePtr = fopen(fileName, "rb");
    if (this->inputFilePtr == NULL){
        perror("fopen");
        exit(-1);
    }
}

/*
Method that create a Packet Structure and
then returns back the packet
*/
int wcount = 0;
void SR_ARQ_Client::createPacket(Packet &newPacket, int seqNo){
    /* Create the packet structure */
   
    newPacket.is_last_pkt = 0;
    newPacket.pkt_type = DATA_PACKET; 
    newPacket.seq_no = seqNo;
    newPacket.payload = "";

    /*  Read char by char from the file upto size of payload */
    char ch;
    int totalCharRead = 0;
    while (totalCharRead < PACKET_SIZE - 1 && (ch = fgetc(this->inputFilePtr)) != EOF){
        newPacket.payload += ch;
        totalCharRead++;
    }

    if(ch == EOF){
        newPacket.is_last_pkt = 1;
    }
    newPacket.pkt_length = totalCharRead; // + PAYLOAD SIZE
}

/*
 Helper method that decode the integer to string
 53 => "0053"
 1254 => "1254"
*/
string SR_ARQ_Client::encodeIntToString(int numb){
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
Create the string in the format
<seq_no><pkt_length><is_last_pkt><pkt_type><payload>
where seq_no, pkt_length, is_last_pkt, pkt_type are of 4 chars each,
*/
string SR_ARQ_Client::encryptPacket(Packet newPacket){
    string message = this->encodeIntToString(newPacket.seq_no) + // 4
        this-> encodeIntToString(newPacket.pkt_length) + // 4
        this-> encodeIntToString(newPacket.is_last_pkt) + // 4
        this-> encodeIntToString(newPacket.pkt_type) + // 4
        newPacket.payload; // size of payload
    return message;
}

/*
Sends the packet to the server
*/
void SR_ARQ_Client::sendPacket(char* buffer, int seqNo, string event){
    // create buffer of pkt_length size
    // cout << "SEND PACKET: " << seqNo << endl;
    // send the packet
    if(seqNo % 2 == 1){
        this->logit(event, "DATA", "CLIENT", "RELAY1", to_string(seqNo));
        sendto(
            this->sockfd_rs1, 
            buffer, 
            HEADERLEN+PACKET_SIZE, 
            0, 
            (const struct sockaddr *) &rs1_saddr,
            this->s_res1_len
        );
        // cout << "Sent to RELAY SERVER 1!! " << endl;
    }
    else{
        this->logit(event, "DATA", "CLIENT", "RELAY2", to_string(seqNo));
        sendto(
            this->sock_fd2, 
            buffer, 
            HEADERLEN+PACKET_SIZE, 
            0, 
            (const struct sockaddr *) &rs2_saddr,
            this->s_res2_len
        );
    }

}

void SR_ARQ_Client::send(){
    // local variables for holding state.
    bool is_last_packet = false;
    int senderWindowSize = 0;

    cout << "Sending file started"<< endl;
    while(true){
        senderWindowSize = 0;
        this->recvWinSize = 0;

        this->senderBuffer = new string[WINDOW_SIZE];
        // put initially -1 to senderWindow
        for(int i = 0; i < WINDOW_SIZE; i++)
            this->senderWindow[i] = -1;

        // Till the window size, send regularly the packets one by one.
        while(senderWindowSize < WINDOW_SIZE){
            //send the Packet
            senderWindowSize++;
            Packet newPacket;
            this->createPacket(newPacket, this->seqNo);
            string encryptedPacket = this->encryptPacket(newPacket);
            char buff[HEADERLEN+PACKET_SIZE];
            strcpy(buff, encryptedPacket.c_str());
            // STORE packet in buffer
            this->senderBuffer[this->seqNo%WINDOW_SIZE] = encryptedPacket;

            this->sendPacket(buff, this->seqNo, "S");
            // add the seq no, after each packet sent.
            this->seqNo++;

            if (newPacket.is_last_pkt == 1){
                is_last_packet = true;
                break;
            }

        }

        // sleep(1);
        // the no. of packets sent, that many listen from the server
        // back.
        while(this->recvWinSize < senderWindowSize){
            bool is_timout = this->recievePacket();
            if(!is_timout){
                // time out occurs
                // all ack not recvd 
                // this->logit("TO", "", "", "");
                // cout << "TIMEOUT !!!!" << endl << endl;
                this->resendDroppedPackets(senderWindowSize);
                break;
            }
        }

        // cout << "ALL("<<senderWindowSize << ") packets successfully sent" << endl << endl;

        // close the connection if the packet is last.
        if(is_last_packet){

            this->closeSocket();
            this->closeFile();
            cout << "CLOSING CONNECTION" << endl;
            break;
        }
        delete[] this->senderBuffer;

    }
}


void SR_ARQ_Client:: resendDroppedPackets(int senderWindSize){
    // send the totalDropped packets
    int totalMissingPackets = 0;

    for(int i = 0; i < senderWindSize; i++){
        if(this->senderWindow[i] == -1){
            char buff[HEADERLEN+PACKET_SIZE];
            strcpy(buff, senderBuffer[i].c_str());
            this->sendPacket(buff, this->seqNo - senderWindSize + i, "RE");
            totalMissingPackets++;
        }
    }

    // recieves the totalDropped packets
    this->recvWinSize = 0;
    while(this->recvWinSize < totalMissingPackets){
        bool is_timout = this->recievePacket();
        if(!is_timout){
            // time out occurs
            // this->logit("TO", "", "", "");
            this->resendDroppedPackets(senderWindSize);
            break;
        }
    }

}


/*
Recieve the packet from the server by listening from the server.
Return the HEADER as valArray[4]
*/
bool SR_ARQ_Client::recievePacket(){
    int maxfdp1;
    fd_set select_fds; 
    struct timeval timeout;
    FD_ZERO(&select_fds);             /* Clear out fd's */
    timeout.tv_sec = TIMEOUT;         /* Timeout set for 5 sec + 0 micro sec*/
    timeout.tv_usec = 0;
    int* valArray;
    char buffer[HEADERLEN+1]; 

    maxfdp1 = max(this->sockfd_rs1, this->sock_fd2) + 1; 
    FD_SET(this->sockfd_rs1, &select_fds); 
    FD_SET(this->sock_fd2, &select_fds); 
    
    if (select(maxfdp1, &select_fds, NULL, NULL, &timeout) == 0 ){
        this->logit("TO", "", "", "", "");
        // cout << "Recieve packet Select has timed out..." << endl;
        return false;
    }
    else{
        if (FD_ISSET(this->sockfd_rs1, &select_fds)) { 
            if (recvfrom(
                    this->sockfd_rs1, buffer, 
                    HEADERLEN+1, 0,
                    (struct sockaddr *) &this->si_me,
                    &this->s_res1_len) == -1){
                die("recvfrom()");
            }
            valArray = decodeMessage(buffer);
            this->recvWinSize++;
            int seqNo_recvd = valArray[0];
            this->senderWindow[seqNo_recvd%WINDOW_SIZE] = seqNo_recvd;
            this->logit("R", "ACK", "RELAY1", "CLIENT", to_string(seqNo_recvd));
            // cout << "Recived ack: " << seqNo_recvd << ", via relay 1!!" << endl;
        }

        if (FD_ISSET(this->sock_fd2, &select_fds)) { 
            if (recvfrom(
                    this->sock_fd2, buffer, 
                    HEADERLEN+1, 0,
                    (struct sockaddr *) &this->si_me,
                    &this->s_res2_len) == -1){
                die("recvfrom()");
            }
            // sleep(1);
            valArray = decodeMessage(buffer);
            this->recvWinSize++;
            int seqNo_recvd = valArray[0];
            this->senderWindow[seqNo_recvd%WINDOW_SIZE] = seqNo_recvd;
            this->logit("R", "ACK", "RELAY2", "CLIENT", to_string(seqNo_recvd));
            // cout << "Recived ack: " << seqNo_recvd << ", via relay 2!!" << endl;
        }
        return true;
    }
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
int* SR_ARQ_Client::decodeMessage(char* msg){
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
 Helper method that decode the string to integer
 For example,
 "0053" => 53 
 "1254" => 1254
*/
int SR_ARQ_Client::decodeStringToInt(char* str, int valBytes){
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

/*----- Closing the file -----*/
void SR_ARQ_Client::closeFile(){
    fclose(this->inputFilePtr);
}

/*----- Closing the socket -----*/
void SR_ARQ_Client::closeSocket(){
    close(this->sockfd_rs1); 
}


int main(int argc, const char *argv[]){
    SR_ARQ_Client clientInstance = SR_ARQ_Client();
    clientInstance.connectSocket();
    clientInstance.send();
    
    return 0;

}
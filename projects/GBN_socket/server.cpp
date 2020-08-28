// modified Go-Back-N ARQ w
#include <iostream> // I/O operations
#include <cstring> // for char* mthods
#include <unistd.h> // for time()
#include <algorithm> // for reverse() function
#include "packet.h" //include Packet strcuture
#include "server.h" // includes server declarations

#define HEADERLEN 16
#define ENCODE_LIMIT 4
#define PORT 8080
#define BUFLEN 1024


using namespace std;

/*
*Construnctor* of GoBackNARQServer
Calls when the object is created
*/
GoBackNARQServer::GoBackNARQServer(){
    // open the file to write
    this->openFile();
}

GoBackNARQServer::~GoBackNARQServer(){}

/*
Method to open the file to write the data 
that is coming
*/
void GoBackNARQServer::openFile(){
    // open the file named "out.txt" in write byte format
    this->outputFilePtr = fopen("out.txt", "wb");
    // if the file not found throw the error
    if(this->outputFilePtr == NULL){
        this->die("openFile()");
    }
}

/*
Write the Message content (without the header)
in the file.
*/
void GoBackNARQServer::writeFile(char* str){
    // seek to the message part which is after HEADERLEN
    fprintf(this->outputFilePtr, "%s", str + HEADERLEN);
}

/*
Method to close the file.
*/
void GoBackNARQServer::closeFile(){
    fclose(this->outputFilePtr);
}

/*
Helper method to show the error and exit the program
*/
void GoBackNARQServer::die(string s){
    perror(s.c_str());
    exit(1);
}  

/*
Method to initialize the server
*/
void GoBackNARQServer::connectSocket(){
    this->sock_fd=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP); 
    if (sock_fd== -1){
        die("socket");
    }
    memset((char *) &si_me, 0, sizeof(si_me));
    this->si_me.sin_family = AF_INET;
    this->si_me.sin_port = htons(PORT);
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
int GoBackNARQServer::decodeStringToInt(char* str, int valBytes){
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
int* GoBackNARQServer::decodeMessage(char* msg){
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
string GoBackNARQServer::encryptACKPacket(Packet* newPacket){
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
string GoBackNARQServer::encodeIntToString(int numb){
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
Packet* GoBackNARQServer::createACKPacket(int ackNo){
    Packet* newPacket = new Packet;
    newPacket->is_last_pkt = 0;
    newPacket->pkt_type = 1;
    newPacket->seq_no = ackNo;
    newPacket->payload = "";
    newPacket->pkt_length = HEADERLEN; // + HEADER + NULL CH
    return newPacket;
}

/*
**Important Method of the class**
*/

void GoBackNARQServer::send(){
    int recv_len;
    char buffer[BUFLEN];
    int is_last_pack = 0; // Stores the last packet or not info
    int ack_no = 0; // stores the ack no to be send
    while(1){
        fflush(stdout);
        //try to receive some data, this is a blocking call
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
        
        // cout << "Mes rec: " << buf << endl;
        // Get the HEADER from the string
        int* valArray = decodeMessage(buffer);
        // write the payload into the file.
        this->writeFile(buffer);
        // fetch the ack_no and is_last_packet flag.
        is_last_pack = valArray[2];
        ack_no = valArray[0];

        cout << "RECEIVE PACKET "<< ack_no << " length " <<  valArray[1];
        if(is_last_pack)
            cout  << " LAST PKT Y" << endl;
        else
             cout << " LAST PKT N" << endl;

        cout << "SEND ACK " << valArray[0] << endl;

        // create a new ACK packet with ack_no
        Packet* newACKPacket = this->createACKPacket(ack_no);
        // encrypt the packet
        string newBUFF = this->encryptACKPacket(newACKPacket);
        // send the ACK packet
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
        // sleep(1);
        // if the packet is last, then close the connection
        if(is_last_pack){
            cout << "CLOSING CONNECTION" << endl;
            this->closeSocket();
            break;
        }

    }
}

/*----- Closing the socket -----*/
void GoBackNARQServer::closeSocket(){
    close(this->sock_fd); 
}


// Driver code 
int main() { 
    // create the object og GBNServer
    GoBackNARQServer serverInstance = GoBackNARQServer();
    // create serevr
    serverInstance.connectSocket();
    // send the process of sending and recieveing
    serverInstance.send();
    return 0; 
} 
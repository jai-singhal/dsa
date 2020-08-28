#include <iostream>
#include <cstring>
#include <algorithm> 
#include <unistd.h>
#include "packet.h"
#include "socket.h"
#include "client.h"

#define HEADERLEN 16
#define ENCODE_LIMIT 4
#define PORT 8080 //DEFAULT PORT
using namespace std;

/*
*Construnctor* of GoBackNARQClient
Calls when the object is created
*/    
GoBackNARQClient::GoBackNARQClient(const char* argv[]){
    ClientSocket.serverIPAddr = argv[1];
    ClientSocket.serverPort = atoi(argv[2]);
    ClientSocket.fileName = argv[3];
    ClientSocket.packetSize = atoi(argv[4]);
    ClientSocket.windowSize = atoi(argv[5]);
    buffer = new char[ClientSocket.packetSize];
    message = new char[ClientSocket.packetSize];
    this->openFile(ClientSocket.fileName);
}

/*
*Construnctor* of GoBackNARQClient
Calls when the object is created
*/   
GoBackNARQClient::~GoBackNARQClient(){
    delete buffer;
    delete message;
}

/*
Helper method to show the error and exit the program
*/
void GoBackNARQClient::die(string s){
    perror(s.c_str());
    exit(1);
}

/*
Method to initialize the Client socket
*/
void GoBackNARQClient::connectSocket(){
    this->sock_fd=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (this->sock_fd == -1){
        this->die("socket");
    }

    memset((char *) &si_other, 0, sizeof(si_other));
    si_other.sin_family = AF_INET;
    si_other.sin_port = htons(this->ClientSocket.serverPort);
    si_other.sin_addr.s_addr = inet_addr(this->ClientSocket.serverIPAddr.c_str());
}

/*
Method to open the file to read the data 
*/
void GoBackNARQClient::openFile(string fileName){
    /*----- Opening the output file -----*/
    this->inputFilePtr = fopen(this->ClientSocket.fileName.c_str(), "rb");
    if (this->inputFilePtr == NULL){
        perror("fopen");
        exit(-1);
    }
}

/*
Method that create a Packet Structure and
then returns back the packet
*/
Packet* GoBackNARQClient::createPacket(int seqNo){
    /* Create the packet structure */
    Packet* newPacket = new Packet;
    newPacket->is_last_pkt = 0;
    newPacket->pkt_type = 0;
    newPacket->seq_no = seqNo;
    newPacket->payload = "";

    /*  Read char by char from the file upto size of payload */
    char ch;
    int totalCharRead = 0;
    while (totalCharRead < this->ClientSocket.packetSize - HEADERLEN - 1 && (ch = fgetc(inputFilePtr)) != EOF){
        newPacket->payload += ch;
        totalCharRead++;
    }

    // if the character read is EOF, then the packet is last packet
    if(ch == EOF){
        newPacket->is_last_pkt = 1;
        this->closeFile();
    }
    // packet length will be total payload size + headerlen + 1(for null ch)
    newPacket->pkt_length = totalCharRead + HEADERLEN + 1; // + HEADER + NULL CH
    return newPacket;
}

/*
 Helper method that decode the integer to string
 53 => "0053"
 1254 => "1254"
*/
string GoBackNARQClient::encodeIntToString(int numb){
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
string GoBackNARQClient::encryptPacket(Packet* newPacket){
    string message = this->encodeIntToString(newPacket->seq_no) + // 4
        this-> encodeIntToString(newPacket->pkt_length) + // 4
        this-> encodeIntToString(newPacket->is_last_pkt) + // 4
        this-> encodeIntToString(newPacket->pkt_type) + // 4
        newPacket->payload; // size of payload
    return message;
}

/*
Sends the packet to the server
*/
bool GoBackNARQClient::sendPacket(int seqNo){
    // create a new packet with the seqNo.
    Packet* newPacket = createPacket(seqNo);
    // create buffer of pkt_length size
    char buffer[newPacket->pkt_length];
    // copy the encrpted packet into buffer
    strcpy(buffer, this->encryptPacket(newPacket).c_str());
    // buffer[newPacket->pkt_length-1] = '\0';

    cout << "SEND PACKET: " << seqNo << endl;
    // send the packet
    sendto(
        this->sock_fd, 
        buffer, 
        newPacket->pkt_length, 
        0, 
        (const struct sockaddr *) &si_other,
        this->slen
    );

    bool is_last_pckt = newPacket->is_last_pkt;
    // delete the heap allocated packet; 
    delete newPacket;
    return is_last_pckt;
}

void GoBackNARQClient::send(){
    // local variables for holding state.
    int seqNo = 0;
    bool is_last_packet = false;
    int senderWindow = 0;
    int recievingWindow = 0;

    while(true){
        senderWindow = 0;
        recievingWindow = 0;
        // Till the window size, send regularly the packets one by one.
        while(senderWindow++ < ClientSocket.windowSize && !is_last_packet){
            //send the Packet
            is_last_packet = this->sendPacket(seqNo);
            // add the seq no, after each packet sent.
            seqNo++;
        }

        sleep(1);
        // the no. of packets sent, that many listen from the server
        // back.
        while(++recievingWindow < senderWindow){
            //receive a reply and print it
            //try to receive some data, this is a blocking call
            int* valArray = this->recievePacket();
            cout << "RECEIVE ACK: " << valArray[0] << endl; 
            delete valArray;
        }
        // close the connection if the packet is last.
        if(is_last_packet){
            this->closeSocket();
            cout << "CLOSING CONNECTION" << endl;
            break;
        }
        sleep(2);
    }
}

/*
Recieve the packet from the server by listening from the server.
Return the HEADER as valArray[4]
*/
int* GoBackNARQClient::recievePacket(){
    int n = 50, len;
    if (
        recvfrom(
            this->sock_fd,  
            this->buffer, 
            1024, 
            0,
            (struct sockaddr *) &this->si_me,
            &this->slen) == -1
    ){
        die("recvfrom()");
    }
    // sleep(1);
    buffer[n] = '\0';
    int* valArray = decodeMessage(buffer);
    return valArray;
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
int* GoBackNARQClient::decodeMessage(char* msg){
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
int GoBackNARQClient::decodeStringToInt(char* str, int valBytes){
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
void GoBackNARQClient::closeFile(){
    fclose(this->inputFilePtr);
}

/*----- Closing the socket -----*/
void GoBackNARQClient::closeSocket(){
    close(this->sock_fd); 
}


int main(int argc, const char *argv[]){
    /*----- variable Declarations  -----*/
    // default arguements
    const char* defaultArgs[] = {
        "client",
        "127.0.0.1", //ip
        "8080", //port
        "test.txt", // input file
        "200", // packet size
        "5" // window size
    };
    FILE *inputFilePtr;

    if(argc == 6){
        GoBackNARQClient clientInstance = GoBackNARQClient(argv);
        clientInstance.connectSocket();
        clientInstance.send();
    }
    else{
		fprintf(stderr, "Usage: <serverIPAddr> <port> <filename> <packetSize> <windowSize> \n");
        cout << "Default arguements are been taken as follows: " << endl;
        cout << "1. IP address as 127.0.0.1" << endl;
        cout << "2. PORT as 8080" << endl;  
        cout << "3. Packet size as 200Bytes" << endl;  
        cout << "5. Windows size as 5" << endl;  

        GoBackNARQClient clientInstance = GoBackNARQClient(defaultArgs);
        clientInstance.connectSocket();
        clientInstance.send();
    }
    
    return 0;

}
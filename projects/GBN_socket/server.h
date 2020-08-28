#ifndef _SERVER_H_
#define _SERVER_H_
// Header file for the Server
#include <iostream>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h> 
#include <netinet/in.h> 
#include "packet.h"

class GoBackNARQServer{
    private:
        FILE *outputFilePtr; // output file pointer
        struct sockaddr_in si_other, si_me;  // socket address self and other
        int sock_fd, i;
        socklen_t slen=sizeof si_other;
        char* buffer;
        char* message;
    
    public:
        GoBackNARQServer();
        ~GoBackNARQServer();
        
        void die(std::string);
        void openFile();
        void writeFile(char*);
        void closeFile();

        void connectSocket();
        int decodeStringToInt(char*, int);
        int* decodeMessage(char*);

        void send();
        std::string encryptACKPacket(Packet*);
        std::string encodeIntToString(int);
        Packet* createACKPacket(int);
        void closeSocket();
};

#endif // _SERVER_H_
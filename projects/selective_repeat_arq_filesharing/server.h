#ifndef _SERVER_H_
#define _SERVER_H_
// Header file for the Server
#include <iostream>
#include <cstring>
#include <algorithm>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>  
#include <sys/types.h>
#include <sys/socket.h>
#include <iomanip>
#include <sys/time.h>
#include <fstream>

#include "packet.h"

#define SERVERPORT 5080 
#define BUFLEN 2048
#define ENCODE_LIMIT 4
#define OUT_FILENAME "out.txt"
#define SERVER_TIMEOUT 5


class SR_ARQ_Server{
    private:
        FILE *outputFilePtr; // output file pointer
        struct sockaddr_in si_other, si_me;  // socket address self and other
        int sock_fd, i;
        socklen_t slen=sizeof si_other;
        std::string recieverBuffer[WINDOW_SIZE];
        int recvWin[WINDOW_SIZE];  
        std::ofstream logger;

    
    public:
        SR_ARQ_Server();
        
        void die(std::string);
        void openFile();
        void closeFile();
        void connectSocket();
        int decodeStringToInt(char*, int);
        int* decodeMessage(char*);
        void send();
        std::string encryptACKPacket(Packet*);
        std::string encodeIntToString(int);
        Packet* createACKPacket(int);
        void closeSocket();
        std::string currentDateTime();
        void logit(std::string, std::string, std::string, std::string, std::string);
};

#endif // _SERVER_H_
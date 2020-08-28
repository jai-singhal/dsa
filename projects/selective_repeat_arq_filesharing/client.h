#ifndef _CLIENT_H_
#define _CLIENT_H_

#include <iostream>
#include <cstring>
#include <algorithm>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>  
#include <sys/types.h>
#include <sys/socket.h>
#include <fstream>
#include <iomanip>
#include <sys/time.h>

#include "packet.h"

#define RELAYIP1 "127.0.0.1"
#define RELAYIP2 "127.0.0.1"
#define RELAYPORT1 5085
#define RELAYPORT2 5088
#define ENCODE_LIMIT 4
#define TIMEOUT 1 //sec
#define INPUT_FILENAME "test.txt"

class SR_ARQ_Client{
    private:
        struct sockaddr_in si_me, rs1_saddr, rs2_saddr; 
        int sockfd_rs1, sock_fd2, i;
        socklen_t s_res1_len=sizeof rs1_saddr;
        socklen_t s_res2_len=sizeof rs2_saddr;
        int recvWinSize;
        char* buffer;
        FILE* inputFilePtr;
        std::string* senderBuffer;
        int senderWindow[WINDOW_SIZE];
        int seqNo;
        std::ofstream logger;

    public:
        SR_ARQ_Client();

        void die(std::string);
        void connectSocket();
        void openFile(const char*);
        void createPacket(Packet &, int);
        std::string encodeIntToString(int);
        std::string encryptPacket(Packet);
        int decodeStringToInt(char*, int);
        int* decodeMessage(char*);
        void sendPacket(char*, int, std::string);
        void send();
        void resendDroppedPackets(int);
        bool recievePacket();
        void closeFile();
        void closeSocket();
        std::string currentDateTime();
        void logit(std::string, std::string, std::string, std::string, std::string);
};

#endif // _CLIENT_H_
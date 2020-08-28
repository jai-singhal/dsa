#ifndef _CLIENT_H_
#define _CLIENT_H_

#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h> 
#include <netinet/in.h> 
#include <iostream>
#include <iostream>
#include "packet.h"
#include "socket.h"


class GoBackNARQClient{
    private:
        Socket ClientSocket;
        struct sockaddr_in si_me, si_other; 
        int sock_fd, i;
        socklen_t slen=sizeof si_other;
        char* buffer;
        char* message;
        FILE* inputFilePtr;

    public:
        GoBackNARQClient(const char* argv[]);

        ~GoBackNARQClient();

        void die(std::string);
        void connectSocket();
        void openFile(std::string);
        Packet* createPacket(int);
        std::string encodeIntToString(int);
        std::string encryptPacket(Packet*);
        int decodeStringToInt(char*, int);
        int* decodeMessage(char*);
        bool sendPacket(int);
        void send();

        int* recievePacket();
        void closeFile();
        void closeSocket();
};

#endif // _CLIENT_H_
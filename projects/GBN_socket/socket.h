
#ifndef _SOCKET_H_
#define _SOCKET_H_

struct Socket{
    std::string serverIPAddr;
    int serverPort;
    std::string fileName;
    int packetSize;
    int windowSize;
};

#endif // _SOCKET_H_
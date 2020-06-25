#ifndef _RELAY_H_
#define _RELAY_H_

#include <iostream>
#include <cstring>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>  
#include <sys/types.h>
#include <sys/socket.h>
#include <fstream>
#include <iomanip>
#include <sys/time.h>

#define MAXTIMEOUT 2
#define MINTIMEOUT 0
#define PDF 0.1
#define SERVER_IP "127.0.0.1"
#define SERVERPORT 5080 
#define RELAYPORT1 5085
#define RELAYPORT2 5088
#define BUFLEN 2000

float randomFloat(float, float );

#endif // _RELAY_H_
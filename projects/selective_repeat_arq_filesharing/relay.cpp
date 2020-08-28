#include "relay.h"

using namespace std;

float randomFloat(float a, float b) {
    // srand(time(0));
    float random = ((float) rand()) / (float) RAND_MAX;
    float diff = b - a;
    float r = random * diff;
    return a + r;
}

int getSeqNumb(char* msg){
    int val = 0;
    int i = 0;
    for(int j = i; j < 4; j++){
        val = val*10 + (msg[j] - '0');
    }
    return val;
}
const std::string currentDateTime() {
   char            fmt[64], buf[64];
   struct timeval  tv;
   struct tm       *tm;
   gettimeofday(&tv, NULL);
   tm = localtime(&tv.tv_sec);
   strftime(fmt, sizeof fmt, "%H:%M:%S.%%06u", tm);
   snprintf(buf, sizeof buf, fmt, tv.tv_usec);
   return buf;
}

int main(int argc, const char *argv[]){
    /*----- variable Declarations  -----*/
    int RELAYPORT;
    std::ofstream logger;
    logger.open ("logs.log", std::ofstream::out | std::ofstream::app);

    if(argc != 2){
        cout << "Must provide the which relay (odd 1/even 1)" << endl;
        return 0;
    }
    int relayServer = atoi(argv[1]);
    const string RELAYNAME = "RELAY" + to_string(relayServer);

    if(relayServer == 1){
        //odd
        RELAYPORT = RELAYPORT1;
    }
    else if (relayServer == 2){
        RELAYPORT = RELAYPORT2;
        //even
    }
    else{
        cout << "Must be 1 or 2" << endl;
        return 0;
    }

    int listenfd, connfd, udpfd1, udpfd2, nready, maxfdp1; 
    char buffer[BUFLEN]; 
    pid_t childpid; 
    fd_set rset; 
    ssize_t n; 
    socklen_t cli_len, serv_len; 
    const int on = 1; 
    struct sockaddr_in cliaddr, servaddr; 

    /* create UDP socket */
    udpfd1 = socket(AF_INET, SOCK_DGRAM, 0); 
    memset((char *) &cliaddr, 0, sizeof(cliaddr));
    cliaddr.sin_family = AF_INET;
    cliaddr.sin_port = htons(RELAYPORT);
    cliaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    bind(udpfd1, (struct sockaddr*)&cliaddr, sizeof(cliaddr)); 

    /* create UDP socket */
    udpfd2 = socket(AF_INET, SOCK_DGRAM, 0); 
    memset((char *) &servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(SERVERPORT);
    servaddr.sin_addr.s_addr = inet_addr(SERVER_IP);
    
    int drop;
    // get maxfd 
    srand(time(0)); // adding seed
    for (;;) { 
        drop = rand();

        if(drop < 0)
            drop = (-1)*drop;

        cli_len = sizeof(cliaddr); 
        serv_len = sizeof(servaddr); 

        bzero(buffer, sizeof(buffer)); 
        n = recvfrom(udpfd1, buffer, sizeof(buffer), 0, 
                        (struct sockaddr*)&cliaddr, &cli_len); 
        
        logger << RELAYNAME << setw(5) << "R" << "    " 
            << currentDateTime() << setw(9) << "DATA" << setw(5) << getSeqNumb(buffer) <<
            "    " << "CLIENT" << setw(9) << RELAYNAME <<  setw(5) << endl;

        // add random delay in microseconds
        float mic_sec = randomFloat(MINTIMEOUT*1000.0, MAXTIMEOUT*1000.0);
        // cout << "Wait for " << mic_sec/1000 << "ms" << endl;
        usleep((int)mic_sec);
        if(drop % 5 == 0){ // data packet drop
            srand(time(0)); // adding seed
            logger << RELAYNAME << setw(5) << "D" << "    " 
            << currentDateTime() << setw(9) << "DATA" << setw(5) << getSeqNumb(buffer) <<
            "    " << "CLIENT" << setw(9) << RELAYNAME << setw(5) << endl;
            continue;
        }

        // send the message back to server
        logger << RELAYNAME << setw(5) << "S" << "    " 
            << currentDateTime() << setw(9) << "DATA" << setw(5) << getSeqNumb(buffer) <<
            "    " << RELAYNAME << setw(9) << "SERVER" << setw(5) << endl;

        sendto(udpfd2, (const char*)buffer, sizeof(buffer), 0, 
                (struct sockaddr*)&servaddr, sizeof(servaddr)); 


        // recieve the ack message from server
        bzero(buffer, sizeof(buffer)); 
        n = recvfrom(udpfd2, buffer, sizeof(buffer), 0, 
                        (struct sockaddr*)&servaddr, &serv_len);
        
        logger << RELAYNAME << setw(5) << "R" << "    " 
            << currentDateTime() << setw(9) << "ACK" << setw(5) << getSeqNumb(buffer) <<
            "    " << "SERVER" << setw(9) << RELAYNAME <<  setw(5) << endl;

        // cout << "Recieved a msg back from server: " << endl;
        
        // send the ack message back to client
        logger << RELAYNAME << setw(5) << "S" << "    " 
            << currentDateTime() << setw(9) << "ACK" << setw(5) << getSeqNumb(buffer) <<
            "    " << RELAYNAME << setw(9) << "CLIENT" <<  setw(5) << endl;
        sendto(udpfd1, (const char*)buffer, sizeof(buffer), 0, 
                (struct sockaddr*)&cliaddr, sizeof(cliaddr)); 
        // cout << "Sent a msg back to client: " << endl;
        

    } 
    logger.close();
    
    return 0;

}
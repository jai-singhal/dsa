// modified Go-Back-N ARQ w
#ifndef _PACKET_H_
#define _PACKET_H_
// Packet structure
struct Packet{
    int pkt_type; // 0 = Data Packet(CLient), 1 = ACK Packet(Server)
    int pkt_length; // For packet length
    int is_last_pkt; // flag 1 if the packet is last
    std::string payload; // data string, empty for ACK
    int seq_no; // seq no of the packet // or ack no.
};

#define ACK_PACKET 1
#define DATA_PACKET 0
// SHOULD remain constant, only developer can change.
#define HEADERLEN 16

// change here, the length of the PAYLOAD
#define PACKET_SIZE 100
// change here, size of rwnd, swnd
#define WINDOW_SIZE 4

#endif // _PACKET_H_
**Problem Statement**: Implement a modified Go-Back-N ARQ protocol
 using UDP sockets.

## How I have done

### Packet forming

I have managed to encrypt the packet in form of string from string.
<seq_no><pkt_length><is_last_pkt><pkt_type><payload>
where seq_no, pkt_length, is_last_pkt, pkt_type are of 4 chars Bytes each,
and payload is the remaining character in packet.
For example
Suppose the packet is: "0001025000010000My name is Jai"
In this,
seq_no = 0001 == 1,
pkt_length = 0250 == 250,
is_last_pkt == 0001 == 1: Yes,
pkt_type === 0000 == 0: Data packet.
and, "My name is Jai" is payload

Read comments for more clearer understanding

-------------------------------------------------------------------

## About files

├── client  ---> Executable client file
├── client.cpp  --> Source code for client
├── client.h  --> Header code for client
├── out.txt  --> Output file
├── packet.h  --> Header file
├── server  ---> Executable Server file
├── server.cpp  --> Source code for Server
├── server.h  --> Source code for Server
├── socket.h   --> Header file
└── test.txt   --> Input file

-------------------------------------------------------------------

## How to run the program

1. Download the jai_singhal_2019H1030021P_assignment.zip and extract it
2. Add the input txt into "test.txt".
3. Compile the server cpp code by
    `
    $ g++ server.cpp -o server
    `
4. Compile the client cpp code by
    `
    $ g++ client.cpp -o client
    `
5. Run the server by-
    `
    $ ./server
    `
6. Run the client by 
    `
    $ ./client <server_ip> <port> <filename> <packet_size> <window_size>
    `

 Default paramters:
    "127.0.0.1", //ip
    "8080", //port
    "test.txt", // input file
    "200", // packet size
    "5" // window size
OR just by using default parameters
    `
    $ ./client
    `
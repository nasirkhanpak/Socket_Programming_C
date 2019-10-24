# C Implementation of Client Server Communication
## Goal: The client reads data from keyboard and send the data to the server. The server receives the data and displays it on the screen. This project helped in gaining deeper understanding of the computer’s socket operations.
o Client reads a line of characters (data) from its keyboard and sends the data to the server; 
o The server receives the data and displays it to its screen.

## Introduction

Sockets are low level endpoint which are used to process information across a network. In this programming assignment we are using C implementation of client-server communication. The client reads data from keyboard and sends the data to the server. The server receives the data and displays it on the screen.

### code description: 

 <netdb.h> for the structures that is used for addresses. Following File Descriptors are used
int server_socket, comm_fd;

    structures are needed to hold IP Address and Port Numbers.
    struct sockaddr_in serveraddr;

The server listens to the client. The above function creates a socket with AF_INET ( IP Addressing ) and of type SOCK_STREAM. An integer is required to hold the socket. I call it server_socket. Results are stored in integer. To call socket function: 

    server_socket = socket(AF_INET, SOCK_STREAM, 0); server_socket = socket(AF_INET, SOCK_STREAM, 0); 


Define few fields on the structure. Followings are some of structures used in the program:

    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = htons(INADDR_ANY);
    serveraddr.sin_port = htons(22000);

 If client send message and the server will accept, and it can be read from comm_fd, and whatever we write using comm_fd will also be sent to the other device.

    comm_fd = accept(server_socket, (struct sockaddr*) NULL, NULL);

## Conclusion

This lab helped me in understanding the details about sockets, ports and socket programming over TCP in C. I tried to do error checks as much as possible in both client and server program. I think it would help to make program much more secure. Error handling is important in cases where the communication between server and client can go wrong at many places as per my understanding. For example, if the connection is not established between server and client and you are wondering where the problem is occuring. Error handling is important especially in case of buffer overflow. 


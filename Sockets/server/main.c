#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdint.h>

int16_t socketCreate(void){
    int16_t hSocket = 0;
    printf("Creating the Socket\n");
    hSocket = socket(AF_INET, SOCK_STREAM, 0);
    /*
        AF_INET - internet protocal
        SOCK_STREAM - socket type
        3rd arg - flags, in this case it means protocal is choose automaticaly
    */
    return hSocket;
}

int bindCreatedSocket(int hSocket){
    int iRetval = -1;
    int clientPort = 12345;

    struct sockaddr_in remote = {0};

    //internet address family
    remote.sin_family = AF_INET;

    //any incoming interface
    remote.sin_addr.s_addr = htonl(INADDR_ANY); //put us on any address they want
    remote.sin_port = htons(clientPort);        //set client port

    iRetval = bind(hSocket, (struct sockaddr *)&remote, sizeof(remote));
    return iRetval;
}

int main(void){
    int socket_desc = 0, sock = 0, clientLen = 0;
    struct sockaddr_in client;
    char client_message[200] = {0};
    char message[100] = {0};
    const char *pMessage = "Hello\n";

    //create socket
    socket_desc = socketCreate();
    if(socket_desc == -1){
        printf("Could not create socket!\n");
        return -1;
    }

    printf("Socket Created!\n");

    //bind
    if(bindCreatedSocket(socket_desc) < 0){
        perror("bind failed!\n");
        return 1;
    }

    printf("bind done\n");

    //listen, dont allow anymore than 3 clients to be waiting
    listen(socket_desc, 3);

    while(1){
        printf("Waiting for incoming connections...\n");
        clientLen = sizeof(struct sockaddr_in);

        //accept connection from an incoming client
        sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t *)&clientLen);

        if(sock < 0){
            perror("accept failed!\n");
            return -1;
        }

        printf("connection accepted!\n");
        //init buffers for reciving and sending
        memset(client_message, '\0', sizeof client_message);
        memset(message, '\0', sizeof message);

        if(recv(sock, client_message, 200, 0) < 0){
            printf("recv failed");
            break;
        }

        printf("Client reply: %s\n", client_message);

        if(strncmp(pMessage, client_message, 5) == 0)
            strcpy(message, "Hi there!");
        else
            strcpy(message, "Invalid Message!");

        //send some data
        if(send(sock, message, strlen(message), 0) < 0){
            printf("Send failed\n");
            return 1;
        }

        close(sock);
        sleep(1);
    }

    return 0;
}
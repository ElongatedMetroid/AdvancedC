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
        3rd arg - flags
    */
    return hSocket;
}

int socketConnect(int hSocket){
    int iRetval = -1;
    int serverPort = 12345;

    struct sockaddr_in remote = {0};
    remote.sin_addr.s_addr = inet_addr("127.0.0.1"); //localhost
    remote.sin_family = AF_INET;
    remote.sin_port = htons(serverPort);

    iRetval = connect(hSocket, (struct sockaddr *)&remote, sizeof(remote));
    return iRetval;
}

int socketSend(int hSocket, char *Rqst, int16_t lenReqst){
    int shortRetval = -1;
    struct timeval tv;
    tv.tv_sec = 20; //20 secs timeout
    tv.tv_usec = 0; 

    if(setsockopt(hSocket, SOL_SOCKET, SO_SNDTIMEO, (char*)&tv, sizeof(tv)) < 0){
        printf("Time Out\n");
        return -1;
    }

    shortRetval = send(hSocket, Rqst, lenReqst, 0);
    return shortRetval;
}

int socketReceive(int hSocket, char* Rsp, int16_t RvcSize){
    int shortRetval = -1;
    struct timeval tv;
    tv.tv_sec = 20; //20 secs timeout
    tv.tv_usec = 0; 

    if(setsockopt(hSocket, SOL_SOCKET, SO_RCVTIMEO, (char*)&tv, sizeof(tv)) < 0){
        printf("Time Out\n");
        return -1;
    }

    shortRetval = send(hSocket, Rsp, RvcSize, 0);
    printf("Response %s\n", Rsp);

    return shortRetval;
}

int main(void){
    int hSocket = 0, read_size = 0;
    struct sockaddr_in server;
    char sendToServer[100] = {0};
    char server_reply[200] = {0};

    hSocket = socketCreate();

    if(hSocket == -1){
        printf("Could not Create Socket\n");
        return -1;
    }

    printf("Socket is created\n");

    if(socketConnect(hSocket) < 0){
        perror("connect failed!\n");
        return -1;
    }

    printf("Sucessfully Connected with Server\n");
    printf("Enter the Message: ");
    fgets(sendToServer, 100, stdin);

    //Send data to server
    socketSend(hSocket, sendToServer, strlen(sendToServer));

    //Recive data from the server
    read_size = socketReceive(hSocket, server_reply, 200);
    printf("server response: %s\n\n", server_reply);

    close(hSocket);

    return 0;
}
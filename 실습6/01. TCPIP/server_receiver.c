#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>

#define SIZE 1024

void receiveFile(int socketfd)
{
    char buffer[SIZE] = {0};

    while (1) {
        int BytesLength = read(socketfd, buffer, sizeof(buffer));

        if(BytesLength <= 0) {
            close(socketfd);
            return;
        }

        printf("[RECEIVE] %s", buffer);
        bzero(buffer, SIZE);
    }

}

int main()
{
    int port = 8080;
    int ret;

    int receiverSocket;
    struct sockaddr_in serverAddress;
    int socketfd;

    receiverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if(receiverSocket < 0) {
        perror("[Error] in socket");
        exit(1);
    }
    
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = port;
    serverAddress.sin_addr.s_addr = htonl(INADDR_ANY); // 0.0.0.0 어떤 IP에 대해서든 열어두기
    
    // bind
    if (bind(receiverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) == -1) {
        perror("[Error] in bind");
        exit(1);
    }

    // listen bind된 소켓으로 대기
    if (listen(receiverSocket, 128) == -1) {
        perror("[Error] in listen");
        exit(1);
    }

    // cliend 요청 accept
    socketfd = accept(receiverSocket, NULL, NULL);

    // printf("socketfd %d\n", socketfd);

    if (socketfd == -1) {
        perror("[Error] in accept");
        exit(1);
    }

    receiveFile(socketfd);
    
    
    printf("\n[CLOSING] Closing the server.\n");
    close(receiverSocket);
    return 0;
}
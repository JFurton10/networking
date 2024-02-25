#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    // 0x12345678 intel
    // 0x78563412
    //
    struct sockaddr_in serverInfo = {0};
    struct sockaddr_in clientInfo = {0};
    int clientSize = 0;

    serverInfo.sin_family = AF_INET;
    serverInfo.sin_addr.s_addr = 0; //bind to every IP on computer
    serverInfo.sin_port = htons(5555); //htons for netowrk-endian

    int fd = socket(AF_INET, SOCK_STREAM, 0); //tcp
    if (fd == -1) {
        perror("socket");
        return -1;
    }

    //bind
    if (bind(fd, (struct sockaddr*) &serverInfo, sizeof(serverInfo)) == -1) {
        perror("bind");
        close(fd);
        return -1;
    }

    //listen
    if (listen(fd, 0) == -1) {
        perror("listen");
        close(fd);
        return -1;
    }

    //accept 
    int cfd = accept(fd, (struct sockaddr*)&clientInfo, &clientSize);
    if (cfd == -1) {
        perror("accept");
        close(fd);
        return -1;
    }
    close(cfd);
}

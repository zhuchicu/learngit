#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in serv_addr = {
        .sin_family = AF_INET,
        .sin_addr.s_addr = inet_addr("127.0.0.1"),
        .sin_port = htons(1234)
    };
    memset(&serv_addr.sin_zero, 0, sizeof(serv_addr.sin_zero));
    connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
    
    char buffer[40];
    read(sock, buffer, sizeof(buffer)-1);
    printf("Message form server: %s\n", buffer);
    
    close(sock);
    return 0;
}
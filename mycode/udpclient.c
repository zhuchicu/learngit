#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define BUF_SIZE 100

int main() {
    int sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    // struct sockaddr_in serv_addr = {  // 服务器地址
    //     .sin_family = AF_INET,
    //     .sin_addr.s_addr = inet_addr("127.0.0.1"),
    //     .sin_port = htons(12345),
    //     .sin_zero = {0}
    // };

    char buf[BUF_SIZE] = {0};

    struct sockaddr_in serv_addr;
    socklen_t serv_addr_size = sizeof(serv_addr);

    while(1) {
        // printf("Input a string: ");
        // gets(buf);
        recvfrom(sock, buf, BUF_SIZE, 0, (struct sockaddr*)&serv_addr, &serv_addr_size);
        printf("From server=%s\n", buf);
        memset(buf, 0, BUF_SIZE);
    }

    close(sock);
    return 0;
}
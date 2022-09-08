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
    int serv_sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    struct sockaddr_in serv_addr = {
        .sin_family = AF_INET,
        .sin_addr.s_addr = htonl(INADDR_ANY),
        .sin_port = htons(12345),
        .sin_zero = {0}
    };
    bind(serv_sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
    char buf[BUF_SIZE] = {0};

    struct sockaddr_in cli_addr;
    socklen_t cli_addr_size = sizeof(cli_addr);
    int inx = 1;
    while(1) {
        char msg[100] = "server data...";
        sprintf(msg+strlen(msg), "%d", inx++);
        strcat(buf, msg);
        //printf("server msg: %s\n", buf);
        sendto(serv_sock, buf, BUF_SIZE, 0, (struct sockaddr*)&cli_addr, cli_addr_size);
        // printf("From client=%s\n", buf);
        memset(buf, 0, BUF_SIZE);
    }

    close(serv_sock);
    return 0;
}

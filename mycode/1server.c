#include <stdio.h>
#include <string.h>  // memset()
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>  // htons()
#include <sys/socket.h>
#include <netinet/in.h>  // socket 结构体定义

int main() {
    int serv_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);  // IPV4，套接字类型，协议标准
    struct sockaddr_in serv_addr = {
        .sin_family = AF_INET,
        .sin_addr.s_addr = inet_addr("127.0.0.1"),
        .sin_port = htons(1234)
    };
    memset(&serv_addr.sin_zero, 0, sizeof(serv_addr.sin_zero));
    bind(serv_sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
    listen(serv_sock, 20);  // 缓冲区的长度（能存放多少个客户端请求
    
    struct sockaddr_in client_addr;
    socklen_t client_addr_size = sizeof(client_addr);
    int client_sock = accept(serv_sock, (struct sockaddr*)&client_addr, &client_addr_size);
    
    char msg[] = "accept msg!";
    write(client_sock, msg, sizeof(msg));
    
    close(client_sock);
    close(serv_sock);
    return 0;
}
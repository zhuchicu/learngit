#include <stdio.h>
#include <string.h>  // memset()
#include <unistd.h>
#include <arpa/inet.h>  // htons()
#include <sys/socket.h>
#include <netinet/in.h>  // socket 结构体定义

#define BUF_SIZE 100

int main() {
    int serv_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);  // IPV4，套接字类型，协议标准
    struct sockaddr_in serv_addr = {
        .sin_family = AF_INET,
        .sin_addr.s_addr = inet_addr("127.0.0.1"),
        .sin_port = htons(12345),
        .sin_zero = {0}
    };
    // memset(&serv_addr.sin_zero, 0, sizeof(serv_addr.sin_zero));
    bind(serv_sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
    listen(serv_sock, 20);  // 缓冲区的长度（能存放多少个客户端请求
    
    struct sockaddr_in client_addr;
    socklen_t client_addr_size = sizeof(client_addr);
    // char w_buff[BUF_SIZE] = {0};
    char r_buff[BUF_SIZE] = {0};
    int client_sock = accept(serv_sock, (struct sockaddr*)&client_addr, &client_addr_size);

    while(1) {
        
        read(client_sock, r_buff, sizeof(r_buff)-1);
        // if(strlen(r_buff) != 0) {
        printf("From client: %s\n", r_buff);
        char *s = " get";
        strcat(r_buff, s);
        write(client_sock, r_buff, sizeof(r_buff));
        memset(r_buff, 0, BUF_SIZE);
   
    }
    
    close(client_sock);
    close(serv_sock);
    return 0;
}
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
    
    struct sockaddr_in serv_addr = {
        .sin_family = AF_INET,
        .sin_addr.s_addr = inet_addr("127.0.0.1"),
        .sin_port = htons(12345),
        .sin_zero = {0}
    };
    // memset(&serv_addr.sin_zero, 0, sizeof(serv_addr.sin_zero));
    char w_buf[BUF_SIZE] = {0};
    char r_buf[BUF_SIZE] = {0};
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

    while(1) {
        
        
        printf("Input a string: ");
        gets(w_buf);
        write(sock, w_buf, sizeof(w_buf));

        read(sock, r_buf, sizeof(r_buf)-1);
        // if(strlen(r_buf) != 0)
        printf("Message form server: %s\n", r_buf);

        memset(w_buf, 0, BUF_SIZE);
        memset(r_buf, 0, BUF_SIZE);
        
    }  
    close(sock);  
    return 0;
}
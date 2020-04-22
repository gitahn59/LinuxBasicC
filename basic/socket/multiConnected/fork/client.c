#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PORTNUM 9000

int main(void){
    int sd, n, rst;
    char buf[256];
    struct sockaddr_in sin;

    memset((char*)&sin, '\0', sizeof(sin));
    sin.sin_family = AF_INET; // internet protocal
    sin.sin_port = htons(PORTNUM);
    sin.sin_addr.s_addr = inet_addr("127.0.0.1");

    sd = socket(AF_INET, SOCK_STREAM,0);
    if(sd == -1){
        perror("socket");
        exit(1);
    }

    rst = connect(sd, (struct sockaddr*)&sin, sizeof(sin));
    if(rst==-1){
        perror("connect");
        exit(1);
    }

    rst = recv(sd, buf, sizeof(buf), 0);
    if(rst == -1){
        perror("recv");
        exit(1);
    }

    printf("** From Server : %s\n", buf);

    strcpy(buf, "I wand a HTTP Service");
    rst = send(sd, buf, sizeof(buf) + 1, 0);
    if(rst == -1){
        perror("send");
        exit(1);
    }
    close(sd);
    return 0;
}
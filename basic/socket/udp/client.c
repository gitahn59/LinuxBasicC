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

    sd = socket(AF_INET, SOCK_DGRAM,0);
    if(sd == -1){
        perror("socket");
        exit(1);
    }

    memset((char*)&sin, '\0', sizeof(sin));
    sin.sin_family = AF_INET; // internet protocal
    sin.sin_port = htons(PORTNUM);
    sin.sin_addr.s_addr = inet_addr("127.0.0.1");

    strcpy(buf, "I am a client.");

    rst = sendto(sd,buf,strlen(buf)+1, 0, (struct sockaddr *)&sin, sizeof(sin));
    if(rst==-1){
        perror("sendto");
        exit(1);
    }

    n = recvfrom(sd, buf, 255, 0, NULL, NULL);
    buf[n] = '\0';
    printf("** From Server : %s\n", buf);

    return 0;
}
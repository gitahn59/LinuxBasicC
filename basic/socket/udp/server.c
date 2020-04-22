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
    int rst;
    char buf[256];
    struct sockaddr_in sin, client;

    int sd, clientlen = sizeof(client);

    sd = socket(AF_INET, SOCK_DGRAM, 0);
    if(sd == -1){
        perror("socket");
        exit(1);
    }

    memset((char*)&sin, '\0', sizeof(sin));
    sin.sin_family = AF_INET; // internet protocal
    sin.sin_port = htons(PORTNUM);
    sin.sin_addr.s_addr = inet_addr("0.0.0.0"); // "0.0.0.0" listen all ip
    memset(&(sin.sin_zero), 0, 8);

    if(bind(sd,(struct sockaddr *)&sin, sizeof(sin))){
        perror("bind");
        exit(1);
    }

    while(1){
        rst = recvfrom(sd, buf,255,0, (struct sockaddr *)&client, &clientlen);
        if(rst == -1){
            perror("recvfrom");
            exit(1);
        }
        
        printf("** From Client : %s\n", buf);
        strcpy(buf, "Hello Client");

        rst = sendto(sd, buf, strlen(buf)+1, 0,(struct sockraddr *)&client, sizeof(client));
        if(rst == -1){
            perror("sendto");
            exit(1);
        }
    }
    return 0;
}
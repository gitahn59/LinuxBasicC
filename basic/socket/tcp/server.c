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
    char buf[256];
    struct sockaddr_in sin, client;

    int sd, ns, clientlen = sizeof(client);


    sd = socket(AF_INET, SOCK_STREAM, 0);
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

    if(listen(sd, 5)){
        perror("listen");
        exit(1);
    }

    ns = accept(sd, (struct sockaddr *)&client, &clientlen);
    if(ns == -1){
        perror("accept");
        exit(1);
    }

    sprintf(buf, "Your IP address is %s", inet_ntoa(client.sin_addr));
    if(send(ns, buf, strlen(buf) + 1 , 0) == -1){
        perror("send");
        exit(1);
    }

    close(ns);
    close(sd);

    return 0;

}
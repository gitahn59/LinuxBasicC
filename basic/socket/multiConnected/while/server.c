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
    int rst;
    struct sockaddr_in sin, client;

    int sd, ns, clientlen = sizeof(client);

    memset((char*)&sin, '\0', sizeof(sin));
    sin.sin_family = AF_INET; // internet protocal
    sin.sin_port = htons(PORTNUM);
    sin.sin_addr.s_addr = inet_addr("0.0.0.0"); // "0.0.0.0" listen all ip

    sd = socket(AF_INET, SOCK_STREAM, 0);
    if(sd == -1){
        perror("socket");
        exit(1);
    }    

    if(bind(sd,(struct sockaddr *)&sin, sizeof(sin))){
        perror("bind");
        exit(1);
    }

    if(listen(sd,5)){
        perror("listen");
        exit(1);
    }

    while(1){
        ns = accept(sd,(struct sockaddr *)&client, &clientlen);
        if(ns == -1){
            perror("accept");
            exit(1);
        }

        sprintf(buf, "%s", inet_ntoa(client.sin_addr));
        printf("*** Send a Message to Client(%s)\n", buf);

        strcpy(buf, "Welcome to Network Server!!!");
        rst = send(ns, buf, strlen(buf)+1, 0);
        if(rst == -1){
            perror("send");
            exit(1);
        }

        rst = recv(ns, buf, strlen(buf), 0);
        if(rst == -1){
            perror("recv");
            exit(1);
        }

        printf("** From Client : %s\n", buf);
        close(ns);
    }
    
    close(sd);
    return 0;
}
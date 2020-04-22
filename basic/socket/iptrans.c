#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    in_addr_t addr;
    struct hostent *hp;
    struct in_addr in;

    char *name = "74.125.129.94"; // google IP
    
    if((addr = inet_addr(name)) == (in_addr_t) -1){
        printf("Error : inet_addr(%s)\n",name);
        exit(1);
    }

    hp = gethostbyaddr((char*)&addr, 4, AF_INET);
    if(hp==NULL){
         (void)printf("Host information not found\n");
         exit(2);
    }

    printf("Name=%s\n", hp->h_name);
    memcpy(&in.s_addr, *hp->h_addr_list, sizeof(in.s_addr));
    printf("IP=%s\n", inet_ntoa(in));

    return 0;
}
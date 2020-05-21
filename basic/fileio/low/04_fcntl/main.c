#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void){
    int fd, flags;
    fd = open("unix.txt", O_RDWR);
    if(fd == -1){
        perror("Open unix.txt");
        exit(1);
    }

    if((flags = fcntl(fd,F_GETFL))==-1){
        perror("fcntl");
        exit(1);
    }

    flags |= O_APPEND;

    if(fcntl(fd, F_SETFL, flags)==-1){
        perror("fcntl");
        exit(1);
    }

    if(write(fd, "test", 4)!=4){
        perror("write");
    }
    
    close(fd);

    return 0;
}

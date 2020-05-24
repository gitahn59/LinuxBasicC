#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

int main(void){
    struct stat buf;
    int mode;

    stat("unix.txt", &buf);

    printf("Mode = %o (16진수: %x)\n", (unsigned int)buf.st_mode, (unsigned int)buf.st_mode);
    mode= buf.st_mode;

    if(S_ISFIFO(mode)){
        printf("unix.txt : FIFO\n");
    }else if(S_ISDIR(mode)){
        printf("unix.txt : Directory\n");
    }else if(S_ISREG(mode)){
        printf("unix.txt : Regular File\n");
    }

    return 0;
}
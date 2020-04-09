#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void){
    pid_t pid;

    if(pid==fork()){
        printf("--> Child Process\n");
        if(execlp("ls","ls","-a",(char*)NULL)==-1){
            perror("execlp");
            exit(1);
        }
    }
    else{
        printf("--> Parent Process - My PID:%d\n",(int)getpid());
    }

    return 0;
}
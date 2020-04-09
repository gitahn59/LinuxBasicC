#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    int status;
    pid_t pid;
    switch(pid=fork()){
        case -1 :
            perror("fork");
            exit(1);
            break;
        case 0: // child process
            printf("Child Process - My PID:%d, My Parent's PID:%d\n",(int)getpid(),(int)getppid());
            if(execlp("./timetable","timetable",argv[1],(char*)NULL)==-1){
                perror("execlp");
                exit(2);
            }   
            exit(2);
            break;
        default: // parent process
            wait(&status);
            printf("Parent Process - My PID:%d, My Parent's PID:%d My Child's PID:%d\n",
                (int)getpid(),(int)getppid(),(int)pid);
            break;
    }

    return 0;
}
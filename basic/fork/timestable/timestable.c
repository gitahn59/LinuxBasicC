#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void){
    pid_t pid;

    switch(pid=fork()){
        case -1 :
            perror("fork");
            exit(1);
            break;
        case 0: // child process
            printf("Child Process - My PID:%d, My Parent's PID:%d\n",(int)getpid(),(int)getppid());
            for(int i=6;i<=9;i++){
                for(int j=1;j<=9;j++){
                    printf("%d X %d = %d\n",i, j, i*j);
                }
            }
            break;
        default: // parent process
            printf("Parent Process - My PID:%d, My Parent's PID:%d My Child's PID:%d\n",
                (int)getpid(),(int)getppid(),(int)pid);
            for(int i=2;i<=5;i++){
                for(int j=1;j<=9;j++){
                    printf("%d X %d = %d\n",i, j, i*j);
                }
            }
            break;
    }

    printf("End of fork\n");
    return 0;
}



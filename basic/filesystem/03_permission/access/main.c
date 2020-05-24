#include <stdio.h>
#include <unistd.h>
#include <sys/errno.h>

extern int errono;

int main(void){
    int per;

    if(access("unix.bak",F_OK) == -1 && errno == ENOENT)
        printf("unix.bak: file not exits.\n");

    per = access("unix.txt", R_OK);
    if(per ==0)
        printf("unix.txt: Read permission is permitted.\n");
    else if(per == -1 && errno == EACCES){
        printf("unix.txt: Read permission is not permitted.\n");
    }

    return 0;
}
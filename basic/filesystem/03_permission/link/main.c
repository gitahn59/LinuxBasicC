#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

int main(void){
    struct stat buf;
    
    stat("unix.txt", &buf);
    printf("Before Link COunt = %d\n", (int)buf.st_nlink);

    //link("unix.txt", "unix.ln");
    symlink("unix.txt", "unix.ln");
    stat("unix.txt", &buf);
    printf("After Link Count = %d\n", (int)buf.st_nlink);

    return 0;
}
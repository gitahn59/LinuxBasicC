#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char **argv){
    DIR *dp;
    struct dirent *dent;
    struct stat sbuf;
    char path[BUFSIZ];

    if(argc!=2){
        printf("Usage : ./myls filename");
        exit(1);
    }

    if((dp = opendir("test"))==NULL){
        perror("opendir : test");
        exit(1);
    }

    while((dent = readdir(dp))){
        printf("%d ", (int)dent->d_ino);
        printf("Name : %s\n", dent->d_name);
    }
    closedir(dp);

    return 0;
}
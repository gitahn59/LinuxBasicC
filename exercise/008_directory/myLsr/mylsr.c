#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

void myls(char* path, char* name){
    DIR *dp;
    struct dirent *dent;
    struct stat buf;
    char next[BUFSIZ];

    stat(path, &buf);

    if(S_ISDIR(buf.st_mode)){ // is direcotry
        dp = opendir(path);
        printf("%d %s\n", buf.st_ino, path);
        while((dent = readdir(dp))){
            sprintf(next, "%s/%s",path, dent->d_name);
            myls(next, dent->d_name);
        }
        closedir(dp);
    }else if(S_ISREG(buf.st_mode)){ // is regular file
        printf("%d %s\n", buf.st_ino, path);
    }
}

int main(int argc, char **argv){
    DIR *dp;

    if(argc!=2){
        printf("Usage : ./myls filename");
        exit(1);
    }

    if((dp = opendir("test"))==NULL){
        perror("opendir : test");
        exit(1);
    }

    closedir(dp);
    myls(argv[1], argv[1]);

    return 0;
}
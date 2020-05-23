#include <stdlib.h>
#include <stdio.h>

int main(){
    FILE *rfp, *wfp;
    char buf[BUFSIZ];

    if((rfp=fopen("unix.txt", "r"))==NULL){
        perror("fopen: unix.txt");
        exit(1);
    }
    
    if((wfp = fopen("unix.out", "a"))==NULL){
        perror("fopen: unixt.out");
        exit(1);
    }

    while((fgets(buf, BUFSIZ, rfp))!=EOF){
        fputs(buf, wfp);
    }

    fclose(rfp);
    fclose(wfp);

    return 0;
}
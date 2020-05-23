#include <stdlib.h>
#include <stdio.h>

int main(){
    FILE *rfp, *wfp;
    int c;

    if((rfp=fopen("unix.txt", "r"))==NULL){
        perror("fopen: unix.txt");
        exit(1);
    }
    
    if((wfp = fopen("unix.out", "w"))==NULL){
        perror("fopen: unixt.out");
        exit(1);
    }

    while((c=fgetc(rfp))!=EOF){
        fputc(c, wfp);
    }

    fclose(rfp);
    fclose(wfp);

    return 0;
}
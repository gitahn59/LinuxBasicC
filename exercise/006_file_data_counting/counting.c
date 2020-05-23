#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv){
    FILE *fp, *wfp;
    char buf[BUFSIZ];
    int n,num;
    
    if(argc!=2){
        printf("Usage : ./counting input_filename\n");
        exit(1);
    }

    if((fp=fopen("num.txt", "r"))==NULL){
        perror("fopen: unix.txt");
        exit(1);
    }

    if((wfp=fopen("four.txt", "w"))==NULL){
        perror("fopen: four.txt");
        exit(1);
    }

    
    while((fscanf(fp, "%d", &num)!=EOF)){
        if(num%4==0)
            fprintf(wfp,"%d\n",num);
    }

    fclose(fp);
    fclose(wfp);

    return 0;
}
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char*argv[]){
    int i = argv[1][0] - '0';

    for(int j=1;j<=9;j++){
        printf("%d X %d = %d\n",i, j, i*j);
    }

    return 0;
}



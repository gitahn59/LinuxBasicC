#include <stdio.h>

void main()
{
    char *temp = "Paras";

    int i = 0;
    temp[0] = 'F';

    for(i=0; i<5;i++){
        printf("%c\n", temp[i]);
    }
}
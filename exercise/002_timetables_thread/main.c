#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void* timetable(void* i){
    int num = *(int*)i;
    for(int j=1;j<=9;j++){
        printf("%d X %d = %d\n", num, j, num*j);
    }
    return NULL;
}

int main(){
    pthread_t thread_id[10];

    for(int i=2;i<=9;i++){
        pthread_create(&thread_id[i], NULL, timetable, (void*)&i);
        pthread_join(thread_id[i],NULL);
        printf("\n");
    }

    return 0;
}
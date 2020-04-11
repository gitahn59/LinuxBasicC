#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define MAX_THREAD 20
pthread_mutex_t m_lock;

void* t_func(void *data){
    int *count = (int*)data;
    int i;
    pthread_t thread_id = pthread_self();

    for(i=0; i<10000; i++){
        pthread_mutex_lock(&m_lock);
        *count = *count+1;
        pthread_mutex_unlock(&m_lock);
    }
}

int main(int argc, char **argv){
    pthread_t thread_id[MAX_THREAD];
    int i = 0;
    int count = 0;

    if(pthread_mutex_init(&m_lock,NULL)!=0){
        perror("Mutex Init failure");
        return 1;
    }

    for(i=0;i<MAX_THREAD;i++){
        pthread_create(&thread_id[i], NULL, t_func, (void*)&count);
    }

    for(i=0; i<MAX_THREAD;i++){
        pthread_join(thread_id[i],NULL);
    }

    printf("Main Thread : %d\n", count);
    return 0;
}
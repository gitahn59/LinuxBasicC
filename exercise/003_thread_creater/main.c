#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

pthread_mutex_t m_lock;

void* t_func(void* n){
    int *num = (int*)n;
    pthread_t thread_id = pthread_self();
    sleep(3);
    pthread_mutex_lock(&m_lock);
    *num = *num+1;
    pthread_mutex_unlock(&m_lock);
    printf("thread %d %d\n", *num, thread_id);
    return NULL;
}

int main(int argc, char **argv){
    int cnt=0;
    pthread_t thread_id[100];

    if(argc==2)
        cnt = atoi(argv[1]);

    if(pthread_mutex_init(&m_lock,NULL)!=0){
        perror("Mutex Init failure");
        return 1;
    }

    int num=0;
    for(int i=1;i<=cnt;i++){
        pthread_create(&thread_id[i], NULL, t_func, (void*)&num);
    }

    for(int i=1;i<cnt;i++){
        pthread_join(thread_id[i],NULL);
    }

    return 0;
}
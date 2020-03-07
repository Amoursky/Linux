#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define THREAD_NUM 2

void* ThreadEntry(void* arg)
{
    (void) arg;
    return NULL;
}

int main()
{
    pthread_t tid[THREAD_NUM];
    int i = 0;
    for(i = 0; i < THREAD_NUM; i++)
    {
        pthread_create(&tid[i], NULL, ThreadEntry, NULL);
    }
    return 0;
}
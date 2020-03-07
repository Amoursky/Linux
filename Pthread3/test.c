#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define THREAD_NUM 2

int g_count = 0;

void* ThreadEntry(void* arg)
{
    (void) arg;
    int i = 0;
    for (i = 0; i < 50000; i++)
    {
        ++g_count;
    }
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
    for(i = 0; i < THREAD_NUM; i++)
    {
        pthread_join(tid[i], NULL);
    }
    return 0;
}
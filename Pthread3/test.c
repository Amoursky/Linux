#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define THREAD_NUM 2
pthread_mutex_t mutex;

int g_count = 0;

void* ThreadEntry(void* arg)
{
    (void) arg;
    int i = 0;
    for (i = 0; i < 50000; i++)
    {   pthread_mutex_lock(&mutex);
        ++g_count;
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main()
{
    pthread_mutex_init(&mutex, NULL);
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
    printf("g_count = %d\n", g_count);

    pthread_mutex_destroy(&mutex);
    return 0;
}
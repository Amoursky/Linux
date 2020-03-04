#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

//  线程之间能共享虚拟地址空间

int g_count = 0;

void* ThreadEntry(void* arg)
{
    int* p = (int*)arg;
    while (1)
    {
        printf("In ThreadEntry\n");
        ++*p;
        sleep(1);
    }
    return NULL;
}

int main()
{
    int* p = (int*)malloc(4);
    pthread_t tid;
    pthread_create(&tid, NULL, ThreadEntry, p);
    pthread_detach(tid);
    while (1)
    {
        printf("In MainThread %d\n", *p);
        sleep(1);
    }
    return 0;
}
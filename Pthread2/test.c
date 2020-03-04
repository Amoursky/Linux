#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

//  线程之间能共享虚拟地址空间

int g_count = 0;

void* ThreadEntry(void* arg)
{
    (void) arg;
    while (1)
    {
        printf("In ThreadEntry\n");
        ++g_count;
        sleep(1);
    }
    return NULL;
}

int main()
{
    pthread_t tid;
    pthread_create(&tid, NULL, ThreadEntry, NULL);
    pthread_detach(tid);
    while (1)
    {
        printf("In MainThread %d\n", g_count);
        sleep(1);
    }
    return 0;
}
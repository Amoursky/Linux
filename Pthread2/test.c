#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void* ThreadEntry(void* arg)
{
    (void) arg;
    while (1)
    {
        printf("In ThreadEntry\n");
        sleep(1);
    }
}

int main()
{
    pthread_t tid;
    pthread_create(&tid, NULL, ThreadEntry, NULL);
    while (1)
    {
        printf("In MainThread\n");
        sleep(1);
    }
    return 0;
}
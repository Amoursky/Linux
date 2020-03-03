#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int arr[1000000] = {0};

void* ThreadEntry(void* arg)
{
    (void) arg;
    while (1)
    {
        for (size_t i = 0; i < sizeof(arr) / sizeof(arr[0]; ++i))
        {
            arr[i] = i;
        }
        return NULL;
    }
}

int main()
{
    pthread_t tid;
    pthread_create(&tid, NULL, ThreadEntry, NULL);
    printf("In MainThread\n");
    pthread_cancel(tid);
    return 0;
}
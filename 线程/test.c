//线程控制的相关函数
// 1. 创建线程
// 2. 终止线程
// 3. 等待线程
// 4. 线程分离

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
        printf("In Main Thread\n");
        sleep(1);
    }
    return 0;
}
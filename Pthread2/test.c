#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>
#include <stdint.h>

// 1. 线程之间能共享虚拟地址空间

#if 0
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
#endif

// 2。线程异常终止的情况
 
#if 0
void* ThreadEntry(void* arg)
{
    (void) arg;
    while(1)
    {
        sleep(1);
        int* p = NULL;
        *p = 10;
    }
    return NULL;
}

int main()
{
    pthread_t tid;
    pthread_create(&tid, NULL, ThreadEntry, NULL);
    while(1)
    {
        printf("In MainThread\n");
        sleep(1);
    }
    return 0;
}
#endif

//3. 多线程利用多核资源

#if 0
void* ThreadEntry(void* arg)
{
    (void) arg;
    while(1);
    return NULL;
}

int main()
{
    pthread_t tid1, tid2;
    pthread_create(&tid1, NULL, ThreadEntry, NULL);
    pthread_create(&tid2, NULL, ThreadEntry, NULL);
    while(1);
    return 0;
}
#endif

//4. 通过多线程提高程序执行效率
// 假设存在一个很大的数组，吧数组中的每个元素都进行一个乘方运算在赋值回数组中

#define SIZE 100000000

int GetUs()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec *1000000 + tv.tv_usec;
}

void Calc(int* arr, int beg, int end)
{
    int i = 0;
    for (i = beg; i < end; ++i)
    {
        arr[i] = arr[i] * arr[i];
    }
}

#if 0
//单线程版本
int main()
{
    int* arr = (int*)malloc(sizeof(int) * SIZE);
    //记录时间开始
    int beg = GetUs();
    Calc(arr, 0 , SIZE);
    //记录结束时间
    int end = GetUs();
    //两个时间做差
    printf("time => %ld\n", end - beg);
    return 0;
}
#endif

#if 1
//多线程版本
#define THREAD_NUM 2

typedef struct Arg
{
    int beg;
    int end;
    int* arr;
}Arg;

void* ThreadEntry(void* arg)
{
    Arg* p = (Arg*)arg;
    Calc(p->arr, p->beg, p->end);
    return NULL;
}

int main()
{
    int* arr = (int*)malloc(sizeof(int) * SIZE);
    Arg args[THREAD_NUM];
    int base = 0;
    int i = 0;
    for (i = 0; i < THREAD_NUM; i++)
    {
        args[i].beg = base;
        args[i].end = base + SIZE / THREAD_NUM;
        args[i].arr = arr;
        base += SIZE / THREAD_NUM;
    }
    pthread_t tid[THREAD_NUM];
    int beg = GetUs();
    for (i = 0; i < THREAD_NUM; i++)
    {
        pthread_create(&tid[i], NULL, ThreadEntry, &args[i]);
    }
    for (i = 0; i < THREAD_NUM; i++)
    {
        pthread_join(tid[i], NULL);
    }
    int end = GetUs();
    printf("time => %ld\n",end - beg);
    return 0;
}
#endif
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

// kill
int main(int argc, char* argv[])
{
    // 为了实现简单，只进行处理一个进程
    if (argc != 3)
    { 
        printf("参数有误! ./mykill [signo] [pid]\n");
        return 1;
    }
    //argv[1] => -9
    int signo = atoi(argv[1] + 1);
    //printf("%d\n", signo);
    pid_t pid = atoi(argv[2]);
    int ret = kill(pid, signo);
    if (ret < 0)
    {
        perror("kill");
        return 1;
    }
    return 0;
}
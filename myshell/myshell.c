#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
//返回值表示 output中包含了几个有效元素
int Split(char input[], char* output[])
{
  char* p = strtok(input, " ");
  int i = 0;
  while(p != NULL)
  {
    //printf("%s\n",p);
    output[i] = (char*)p;
    //printf("%s\n",output[i]);
    ++i;
    p = strtok(NULL, " ");
  }
  output[i] = NULL;// 这个操作是很容易被遗忘的
  return i;
}

void CreateProcess(char* argv[], int n)
{
  (void) n;
  
  //1.创建子进程
  pid_t ret = fork();
  if (ret > 0)
  {
    // father
    //暂时先这么写，正常的话一个 shell 是应该知道子进程的退出码的
    wait(NULL); 
  }
  else if(ret == 0)
  {
    //child
    ret = execvp(argv[0], argv);
    if (ret < 0)//if 条件可以省略，如果 exec 成功了，是肯定不会执行到这个代码的
    {
      perror("exec");
      exit(0);
    }
  }
  else
  {
    perror("fork");
  }
  //2.父进程进行进程等待，子进程进行程序替换
}

int main()
{
  while(1)
  {
    //1 打印一个提示符
    printf("[dev@localhost ~]$ ");
    fflush(stdout);
    //2.用户输入一个指令
    char command[1024] = {0};
    //scanf("%s",command);
    gets(command);//一次读一行数据
    //测试下 scanf 能否读入一行数据
    //printf("%s\n",command);
    //3.解析指令,把要执行的是哪个程序识别出来
    // 那些是命令行参数识别出来
    // 切分结果应该是一个字符串数组
    char* argv[1024];
    int n = Split(command, argv); 
    //4.创建子进程并且进行程序替换
    //printf("%s\n",argv[0]);
    CreateProcess(argv,n);
  }  
  return 0;
}

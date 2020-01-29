#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

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
    printf("%s\n",command);
    //3.解析指令,把要执行的是哪个程序识别出来
    // 那些是命令行参数识别出来
  }  
  return 0;
}

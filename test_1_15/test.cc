#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
//void Func()
//{
//  printf("goodbye!\n");
//}
//
//int main()
//{
//  //for(int i = 0; i < 2; i++)
//  //{
//  //  fork();
//  //  printf("=");
//  //  fflush(stdout);
//  //}
//  //_exit(0);
//  //atexit(Func);
//  int *p = NULL;
//  *p = 10;
//  printf("hehe\n");
//  return 0;
//}

int main()
{
  pid_t ret = fork();
  if(ret > 0)// father
  {
    printf("father %d\n",getpid());
    int status = 0;
    pid_t result = wait(&status);  //status 是一个输出型变量
    printf("result %d\n",result);
    if(status & 0xff)
    {
      //异常终止
      printf("异常终止，信号为 %d\n",status & 0x7f);
    }
    else
    {
      //正常终止
      printf("正常终止，退出码为 %d\n",(status >> 8) & 0xff);
    }
  } 
  else if(ret == 0)// child
  { 
    int count = 3;
    while(count > 0)
    {
      printf("child %d\n",getpid());
      sleep(1);
      count--;
    }
    exit(0);
  }
  else//错
  {
    perror("fork");
  }
  return 0;
}

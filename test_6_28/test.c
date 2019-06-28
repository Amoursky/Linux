#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
//void exit(int status);
//int main()
//{
//  printf("hello");
//  //exit(0);
//  _exit(0);
//}
int main()
{
  pid_t pid;
  if((pid=fork()) ==  -1 )
  {
    perror("fork");
    exit(1);
  }
  if( pid == 0 )
  {
    sleep(20);
    exit(10);
  }
  else 
  {
    int st;
    int ret = wait(&st);
    if(ret > 0 && ( st & 0x7F ) == 0 )//正常退出
    {
      printf("child exit code:%d\n",(st>>8)&0xFF);
    }
    else if(ret > 0)//异常退出
    {
      printf("sig code : %d\n",st&0x7F);
    }
  }
}

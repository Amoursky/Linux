#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int main()
{
  //最后一个参数必须是NULL，如果不填，程序就是未定义行为
  pid_t ret = fork();
  if(ret == 0)
  {
    char* env[] = 
    {
      "AAA=BBB",
      NULL
    };
    //child
    printf("before execl\n"); 
    //execl("usr/bin/ls","usr/bin/ls","/",NULL);
   execle("./aaa","./aaa","/",NULL,env);
  }
  //father
  wait(NULL);
  printf("after execl %d\n",ret);
  return 0;
} 

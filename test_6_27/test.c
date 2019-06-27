#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
//int main()
//{
// int ret = fork();
// if(ret<0)
// {
//   perror("fork");
// }
// if(ret==0)//child
// {
//  printf("I am child %d ; ret = %d\n",getpid(),ret);
// }
// else
// {
//   printf("I am father %d ; ret = %d\n",getpid(),ret);
// }
// sleep(1);
// return 0;
//}
int main()
{
  pid_t pid;
  printf("Before : %d\n",getpid());
  if((pid=fork())== -1)
  {
    perror("fork");
    exit(1);
  }
  printf("After : pid = %d,forkr return %d\n",getpid(),pid);
  sleep(1);
  return 0;
}

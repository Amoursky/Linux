#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
  //最后一个参数必须是NULL，如果不填，程序就是未定义行为
  printf("before execl\n");
  int ret = execl("/usr/bin/ls","/usr/bin/ls","/",NULL);
  printf("after execl %d\n",ret);
  return 0;
}

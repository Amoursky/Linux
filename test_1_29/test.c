#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
  execl("/usr/bin/ls","/usr/bin/ls","/",NULL);

  return 0;
}

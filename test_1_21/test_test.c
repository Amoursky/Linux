#include<stdio.h>
#include<unistd.h>
int main()
{
  int i = 0;
  for(i = 0; i < 2; i++)
  {
    fork();
    printf("=");
    fflush(stdout);
  }
  return 0;
}

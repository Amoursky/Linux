#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
// class Test
// {
//     void func()
//     {}
//     void func() const
//     {}
// }

// void func()
// {
//     FILE* fp = fopen("test.txt","r")
//     fclose(fp);
// }

// int main()
// {
//     func(); 
//     return 0;
// }

int main()
{
    int fd = open("./test.txt",01);
    printf("fd = %d\n", fd);
    return 0;
}
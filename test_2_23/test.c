#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
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
    //open的返回值叫做文件描述符
    // printf("%d\n",stdin->_fileno);
    // printf("%d\n",stdout->_fileno);
    // printf("%d\n",stderr->_fileno);
    int fd = open("./test.txt",O_WRONLY);
    if (fd < 0)
    {
        perror("open");
        return 1;
    }
    // 读文件
    // char buf[1024] = {0};
    // ssize_t n = read(fd, buf, sizeof(buf) - 1);
    // buf[n] = '\0';
    // printf("%s\n", buf);

    // 写文件
    char buf[1024] = "hehe";
    ssize_t n = write(fd, buf, strlen(buf));
    close(fd);
    return 0;
}

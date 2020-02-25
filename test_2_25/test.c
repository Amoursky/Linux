#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    close(1);
    int fd = open("test.txt", O_WRONLY);
    fprintf(stderr, "fd = %d\n", fd);
    //printf("%d\n",stdout->_fileno); 
    return 0;
}
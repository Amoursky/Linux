#include <stdio.h>
#include <unistd.h>

int main()
{
    //close(1);
    printf("%d\n",stdout->_fileno);
    return 0;
}
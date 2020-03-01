#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <sstream>

//kill
int main()
{
    // C 语言字符串转整数
    // 1. atoi
    // char str[] = "100";
    // int num = atoi(str);
    // printf("%d\n",num);

    //2. sprintf/sscanf
    // char str[] = "100";
    // int num = 0;
    // sscanf(str, "%d", &num);
    // printf("%d\n",num);

    std::stringstream ss;
    std::string str = "100";
    int num = 0;
    ss << str;
    ss >> num;
    std::cout << num << std::endl;
    return 0;
}
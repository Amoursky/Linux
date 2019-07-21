#include"udp_server.hpp"

// void Echo(const std::string& req,std::string* resp)
// {
//     *resp =req;
// }

int main()
{
    UdpServer server;
    // lanbada 表达式 本质上是一个 匿名函数
    server.Start("0.0.0.0",9090,[](const std::string& req,std::string* resp)
    {
        *resp = req;
    });
    return 0;
}

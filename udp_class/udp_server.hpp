#pragma once
#include"udp_socket.hpp"
#include<cassert>
#include<functional>

//通用的 Udp 服务器类
//1.读取请求
//2.根据请求计算响应
//3.把响应写回客户端
//其中1，3是固定套路，不管是啥场景，代码都一样
//2是和业务相干，所以就把 2 对应的代码提取成一个回调函数

//typedef void (*Handle)(const std::string& req,std::string* resp);
typedef std::function<void(const std::string&,std::string*)> Handler;
class UdpServer
{
public:
    UdpServer()
    {
        assert(sock_.Socket());
    }
    ~UdpServer()
    {
        sock_.Close();
    }
    bool Start(const std::string& ip,uint16_t port,Handler handler)
    {
        //1.创建 socket（已经完成）
        //2.绑定端口号
        bool ret = sock_.Bind(ip,port);
        if(!ret)
        {
            return false;
        }
        //3.进入一个死循环
        while(true)
        {
            //处理每个请求
            //a）读取请求
            std::string req;
            std::string peer_ip;
            uint16_t peer_port;
            sock_.RecvFrom(&req,&peer_ip,&peer_port);
            //b)根据请求计算响应
            std::string resp;
            handler(req,&resp);
            //c)把响应返回客户端
            sock_.SendTo(resp,peer_ip,peer_port);
        }
    }
private:
    UdpSocket sock_;
};

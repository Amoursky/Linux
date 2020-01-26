//通用的 TCP 服务器
#pragma once
#include"tcp_socket.hpp"

typedef std::function<void (const std::string&,std::string*)>Handler;

class TcpSever
{
public:
  TcpSever()
  {

  }

  bool Start(const std::string& ip,uint16_t port,Handler handler)
  {
    //1.先创建一个 socket
    bool ret = listen_sock_.Socket();
    if(!ret)
    {
      perror
    }
  }


private:
  TcpSever listen_sock_;
};

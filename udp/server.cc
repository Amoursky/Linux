#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<unistd.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
int main()
{
    //先创建一个socket
    //AF_INET是一个宏，表示ipv4协议
    //SCK_DGRAM 表示使用 udp 协议
    int sock=socket(AF_INET,SOCK_DGRAM,0);
    if(sock < 0)
    {
        perror("socket");
        return 1;
    }
    //把当前的 socket 绑定上一个 IP + 端口号
    sockaddr_in addr;
    addr.sin_family=AF_INET;//使用哪一个协议家族？？
    //IP地址也是一个整数，也需要转成网络字节序，只不过inet_addr函数自动转了
    addr.sin_addr.s_addr=inet_addr("0.0.0.0");//设置IP地址
    //端口号必须先转成网络字节序
    addr.sin_port=htons(9090);
    int ret=bind(sock,(sockaddr*)&addr,sizeof(addr));
    if(ret<0)
    {
        perror("bind");
        return 1;
    }
    printf("server start ok!\n");

    //处理服务器收到的请求
    while(true)
    {
        //读取客户端的请求
        sockaddr_in peer;
        socklen_t len=sizeof(peer);//输入输出参数
        char buf[1024]={0};
        ssize_t n=recvfrom(sock,buf,sizeof(buf)-1,0,(sockaddr*)&peer,&len);//面向数据报的函数接口
        if(n<0)
        {
            perror("recvform");
            continue;//考虑到容错，不要因为一次请求失败就放弃
        }
        buf[n]='\0';
        //根据请求计算响应
        //略，此处写的是一个回显
        //把响应写回客户端
        n=sendto(sock,buf,strlen(buf),0,(sockaddr*)&peer,len);
        if(n<0)
        {
            perror("sendto");
            continue;
        }
        printf("[%s:%d] buf: %s\n",inet_ntoa(peer.sin_addr),ntohs(peer.sin_port),buf);
    }
    close(sock);
    return 0;
}
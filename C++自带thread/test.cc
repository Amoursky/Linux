#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<string>
//C++中自带的 std::thread
//C++ 11 开始，把线程直接纳入到标准库之中
//std::thread 类
//信号量（目前还没有）
//读写锁（目前还没有）
//原子操作
#include<thread>
#include<mutex>
#include<atomic>
using namespace std;

mutex lock;
atomic_int count(0);
//原子操作将原来修改一个变量的的三个操作变成一个操作
//原子操作本质上也是锁，只不过是CPU指令级别的锁
//这样的锁本质是  自旋锁
void Handler()
{
  for(int i=0;i<5000;++i)
  {
    ++count;
  }
}

int main()
{
  //thread 构造函数用到的语法 变长参数模板
  thread t1(Handler);
  thread t2(Handler);
  t1.join();
  t2.join();
  printf("count=%d\n",(int)count);
  return 0;
}

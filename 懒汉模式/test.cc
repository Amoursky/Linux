#include<iostream>
using namespace std;
template<typename T>
class Singleton
{
  public:
    static T* Instance()
    {
      if(inst_==NULL)//双重if判断考虑效率问题
      {
        lock();//加锁保证线程安全
      if(inst_ ==NULL)
      {
        inst_=new T();
      }
      unlock();
      return inst_;
    }
    }
  private:
   volatile static T* inst_=NULL;//考虑编译器优化问题
};


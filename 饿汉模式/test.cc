#include<iostream>
using  namespace  std;
template<typename T>
class Singleton
{
  public:
    static T* Instance()
    {
      return &inst_;
    }
 private:
    static T inst_;
};

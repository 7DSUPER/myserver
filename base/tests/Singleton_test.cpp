#include "../Singleton.h"
#include "../CurrentThread.h"
#include "../Thread.h"

#include <boost/noncopyable.hpp>
#include <stdio.h>

class Test : boost::noncopyable
{
 public:
  Test()
  {
    printf("tid=%d, constructing %p\n", x7m::CurrentThread::tid(), this);
  }

  ~Test()
  {
    printf("tid=%d, destructing %p %s\n", x7m::CurrentThread::tid(), this, name_.c_str());
  }

  const std::string& name() const { return name_; }
  void setName(const std::string& n) { name_ = n; }

 private:
  std::string name_;
};

void threadFunc()
{
  printf("son tid=%d, %p name=%s\n",
         x7m::CurrentThread::tid(),
         &x7m::Singleton<Test>::instance(),
         x7m::Singleton<Test>::instance().name().c_str());
  x7m::Singleton<Test>::instance().setName("only one, changed");
}

int main()
{
  x7m::Singleton<Test>::instance().setName("only one");
  x7m::Thread t1(threadFunc);
  t1.start();
  t1.join();
  printf("parent tid=%d, %p name=%s\n",
         x7m::CurrentThread::tid(),
         &x7m::Singleton<Test>::instance(),
         x7m::Singleton<Test>::instance().name().c_str());
}

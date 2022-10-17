#include "../ThreadLocalSingleton.h"
#include "../CurrentThread.h"
#include "../Thread.h"
#include <boost/bind.hpp>
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

void threadFunc(const char* changeTo)
{
  printf("tid=%d, %p name=%s\n",
         x7m::CurrentThread::tid(),
         &x7m::ThreadLocalSingleton<Test>::instance(),
         x7m::ThreadLocalSingleton<Test>::instance().name().c_str());
  x7m::ThreadLocalSingleton<Test>::instance().setName(changeTo);
  printf("tid=%d, %p name=%s\n",
         x7m::CurrentThread::tid(),
         &x7m::ThreadLocalSingleton<Test>::instance(),
         x7m::ThreadLocalSingleton<Test>::instance().name().c_str());

  // no need to manually delete it
  // muduo::ThreadLocalSingleton<Test>::destroy();
}

int main()
{
  x7m::ThreadLocalSingleton<Test>::instance().setName("main one");
  x7m::Thread t1(boost::bind(threadFunc, "thread1"));
  x7m::Thread t2(boost::bind(threadFunc, "thread2"));
  t1.start();
  t2.start();
  t1.join();
  printf("tid=%d, %p name=%s\n",
         x7m::CurrentThread::tid(),
         &x7m::ThreadLocalSingleton<Test>::instance(),
         x7m::ThreadLocalSingleton<Test>::instance().name().c_str());
  t2.join();

  pthread_exit(0);
}

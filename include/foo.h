#ifndef FOO_H
#define FOO_H

#include <iostream>

class Foo{
  public:
    void bar(){
      std::cout << "Hello from C++!" << std::endl;
      int a = 123456 * 123456; // overflow
      std::cout << a << std::endl;
    }
};


#ifdef __cplusplus
extern "C" {
#endif

  Foo* Foo_new();
  void Foo_bar(Foo* foo);
  void Foo_delete(Foo* foo);

#ifdef __cplusplus
}
#endif


#endif // FOO_H

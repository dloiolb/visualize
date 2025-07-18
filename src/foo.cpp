#include "foo.h"

Foo* Foo_new() {
  return new Foo();
}

void Foo_bar(Foo* foo){
  foo->bar();
}

void Foo_delete(Foo* foo){
  delete foo;
}

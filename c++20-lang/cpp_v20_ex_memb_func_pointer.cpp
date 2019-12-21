#include <iostream>

struct S {
   S() : i(0) {}
   mutable int i;
};
void f() 
{
  S cs;
  int S::* pm = &S::i;
  cs.*pm = 88;
}

int main(const int argc, const char* const argv[]) {
   f();
   
   return 0;
}

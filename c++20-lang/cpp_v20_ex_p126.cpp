#include <iostream>

struct S {
  S() : i(0) {}
  mutable int i;
};

void f() {
  S cs;
  int S::* pm = &S::i;
  cs.*pm = 88;
  std::cout << "cs.i=" << cs.i << "\n";
}

int main(const int argc, const char *argv[]) {
  f();
  return 0;
}

#include <iostream>

class A {
public:
   A() {};
   A(A* a) { i = a->i; };
private:
   int i;
};

int main() {

   return 0;
}

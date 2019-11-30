#include <iostream>

class X {};
class Y : public virtual X {};
class Z : public virtual X {};
class A : public Y, public Z {};

int main(const int argc, const char * const argv[]) {

int x = sizeof(X);
int y = sizeof(Y);
int z = sizeof(Z);
int a = sizeof(A);

std::cout << "sizeof X = " << x << ", sizeof Y = " << y << ", sizeof Z = " << z << ", sizeof A = " << a << std::endl;
X x1, x2;
if ( &x1 == &x2 ) std::cerr << "yipes!" << std::endl;

return 0;

}

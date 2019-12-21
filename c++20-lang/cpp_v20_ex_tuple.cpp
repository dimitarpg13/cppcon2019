#include <iostream>

struct S { static const int x = 0; };
const int &f(const int &r) { return r; };

int main (const int argc, const char * const argv[]) {
    bool b = true;
    //int n = b ? (1, S::x) : f(S::x);
    std::cout << "S::x = " << S::x << std::endl;
    auto pr = (1, S::x); 
    std::cout << pr << std::endl;
    return 0;
}

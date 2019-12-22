#include <memory> 
#include <iostream>


int main(const int argc, const char * const argv[]) {
    auto derefLess = [](const std::unique_ptr<int> & p1, const std::unique_ptr<int> & p2)
    { return *p1 < *p2; };
    int * i1 = new int;
    *i1 = 100;
    int * i2 = new int;
    *i2 = 1001;
    std::unique_ptr<int> p1 ( i1 );
    std::unique_ptr<int> p2 ( i2 );
    std::cout << derefLess(p1, p2) << std::endl;
    return 0;
}

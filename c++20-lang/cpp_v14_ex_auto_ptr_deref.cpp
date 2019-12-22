#include <memory> 
#include <iostream>


int main(const int argc, const char * const argv[]) {
    auto derefLess = [](const auto& p1, const auto& p2)
    { return *p1 < *p2; };
    std::unique_ptr<int> p1 = std::make_unique<int>(100);
    std::unique_ptr<int> p2 = std::make_unique<int>(1000);
    std::cout << derefLess(p1, p2) << std::endl;
    return 0;
}

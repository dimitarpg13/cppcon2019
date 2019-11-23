#include <iostream>
#include <cfloat>
#include <math.h>
#include <cmath>
#include <experimental/coroutine>
using namespace std;
void foo() {
    std::cout << "Hello" << std::endl;
    co_await std::experimental::suspend_always();
    std::cout << "World" << std::endl;

}

int main() {

    return 0;
}

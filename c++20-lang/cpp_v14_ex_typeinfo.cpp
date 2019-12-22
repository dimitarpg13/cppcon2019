#include <iostream>
#include <vector>

class Widget {

};

template<typename T>   // template func
void f(const T& param); // to be called

std::vector<Widget> createVec(); // factory function

template<typename T>
void f(const T& param)
{
    using std::cout;
    cout << "T =   " << typeid(T).name() << '\n'; // show T
    cout << "param = " << typeid(param).name() << '\n';
}

std::vector<Widget> createVec() {
    std::vector<Widget> res = { Widget() };
    return res;
}

int main(const int argc, const char * const argv[]) {

    const auto vw = createVec();  // init vw w/factory return 
    if (!vw.empty()) {
       f(&vw[0]);
    }
    return 0;
}

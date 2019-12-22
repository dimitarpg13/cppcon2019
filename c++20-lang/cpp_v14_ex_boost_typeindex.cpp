#include <iostream>
#include <vector>
#include <boost/type_index.hpp>

class Widget {

};

template<typename T>   // template func
void f(const T& param); // to be called

std::vector<Widget> createVec(); // factory function

template<typename T>
void f(const T& param)
{
    using std::cout;
    using boost::typeindex::type_id_with_cvr;

    // show T
    cout << "T =   " 
         << type_id_with_cvr<T>().pretty_name()
         << '\n';

    // show param's type
    cout << "param = "
         << type_id_with_cvr<decltype(param)>().pretty_name()
         << '\n';
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

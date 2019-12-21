#include <iostream>
#include <vector>

template <typename T>
class MyType {
public:
    template <typename D>
    MyType(D&& data) { };
    T _value; 
};

/*template <typename T>
template <typename D>
MyType<T>::MyType<D>(D&& data) {

};*/

template <typename T>
class MyContainer {
public:
    bool add(T&& val) { _array.push_back(std::move(val)); }

    MyType<T>& operator[](const int);
protected:
    std::vector<T> _array;
};

template<typename Container, typename Index>
decltype(auto)
access(Container& c, Index i)
{
  return c[i];
}

int main (const int argc, const char * const argv[]) {

  return 0;
}

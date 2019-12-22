#include <iostream>
#include <utility>
#include <vector>

template <typename VT>
class MyType {
public:
    template <typename D>
    MyType(D&& data) : _value(data) { };
    VT& value() { return _value; }
protected:
    VT _value; 
};

template <typename T>
class MyContainer {
public:
    template <typename TT>
    void add(TT&& val) { _array.push_back(std::forward<TT>(val)); }

    T& operator[](const int idx) { return _array[idx]; }
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
  MyType<float> a(1001);
  MyContainer<MyType<float>> container;
  container.add(std::move(a));
  std::cout << access(container, 0).value() << std::endl;

  return 0;
}

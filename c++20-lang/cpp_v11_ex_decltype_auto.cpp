#include <iostream>
#include <utility>
#include <vector>

template <typename VT>
class MyType {
public:
    template <typename D>
    MyType(D&& data) : _value(data) { };
    const VT& value() const { return _value; }
    friend std::ostream & operator << (std::ostream &out, const MyType<VT> &c) {
	   out << c.value() ;
	   return out;
    } 
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
auto
access(Container& c, Index i) -> decltype(std::forward<Container>(c)[i])
{
  return std::forward<Container>(c)[i];
}

int main (const int argc, const char * const argv[]) {
  MyType<float> a(1001);
  MyContainer<MyType<float>> container;
  container.add(std::move(a));
  std::cout << access(container, 0) << std::endl;

  return 0;
}

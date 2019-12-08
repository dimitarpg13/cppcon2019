#include <iostream>


template<typename T>
T adder(T v) {
#ifdef DEBUG
    std::cout << __PRETTY_FUNCTION__ << "\n";
#endif
    return v;
}

template<typename T, typename... Args>
T adder(T first, Args... args) {
#ifdef DEBUG
    std::cout << __PRETTY_FUNCTION__ << "\n";
#endif
    return first + adder(args...);
}

int main (const int argc, const char * const argv[]) {
  long sum = adder(1, 2, 3, 8, 7);
  std::cout << "sum=" << sum << "\n";
  return 0;
}

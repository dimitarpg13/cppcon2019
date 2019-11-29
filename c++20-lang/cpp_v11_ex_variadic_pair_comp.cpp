#include <iostream>
#include <iomanip>

template<typename T>
bool pair_comparer(T a, T b) {
  // in real-world code, we could not compare floating point values like
  // this. It would make sense to specialize this function for floating point
  // types to use approximate comparison.
  return a == b;
}

template<typename T, typename... Args>
bool pair_comparer(T a, T b, Args... args) {
    return a == b && pair_comparer(args...);
}

int main(const int argc, const char* const argv[]) {
    std::cout << std::boolalpha;
    std::cout << "pair_comparer(1.5, 1.5, 2, 2, 6, 6) = " << pair_comparer(1.5, 1.5, 2, 2, 6, 6) << "\n";

   return 0;
}

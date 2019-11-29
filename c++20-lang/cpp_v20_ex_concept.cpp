#include <iostream>

template <class T, class U>
concept Derived = std::is_base_of<U, T>::value;

int main(const int argc, const char* const argv[]) {

   return 0;
}

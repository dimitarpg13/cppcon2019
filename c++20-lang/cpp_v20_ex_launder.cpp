#include <iostream>
#include <new>

int main(const int argc, const char* const argv[]) {
  int x[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  auto p = std::launder(reinterpret_cast<int(*)[10]>(&x[0]));
  std::cout << "x[3]=" << (*p)[3] << std::endl;
}

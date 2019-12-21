#include <iostream>
#include <vector>

int main(const int argc, const char * const argv[]) {
  std::vector<int> v = { 1, 2, 3};
  auto resetV = [&v](const auto& newValue) { v = newValue; };
  resetV({ 1, 2, 3, 4});
  //v = {1, 2, 3, 4};
  for (int i = 0; i < v.size(); ++i) {
     std::cout << v[i] << std::endl;
  }
  return 0;
}

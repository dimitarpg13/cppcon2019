#include <iostream>

template<class T> concept C = requires(T a, T b, const T c, const T d) {
  c == d;
  a = std::move(b);
  a = c;
};

int main(const int argc, const char* argv[]) {

   return 0;
}

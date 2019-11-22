#include <iostream>

// In a trailing-return-type, the class being defined is not required to be complete for purposes of class
// member access (7.6.1.4). Class members declared later are not visible.
//
// Note on trailing-return-type:
// In C++03, the return type of a function template cannot be generalized if the return type relies on 
// those of the template arguments. To solve this problem, C++11 introduced a feature called 
// trailing return types:
// template<class T>
// auto mul(T a, T b) -> decltype(a*b){
//    return a*b;
// }
// more on trailing return types: 
// https://www.ibm.com/developerworks/community/blogs/5894415f-be62-4bc0-81c5-3956e82276f3/entry/introduction_to_the_c_11_feature_trailing_return_types?lang=en
// 



struct A {
  char g();
  template<class T> auto f(T t) -> decltype(t + g())
     { return t - g(); }
};
char A::g() { return 'a'; };
template auto A::f(int t) -> decltype(t + g());

int main(const int argc, const char *argv[]) {
  A a;
  char c='k';
  std::cout << "a.f(c)=" << a.f(c) << "\n";
  int d= (int) c;
  std::cout << "a.f(d)=" << a.f(d) << "\n";
  return 0;
}

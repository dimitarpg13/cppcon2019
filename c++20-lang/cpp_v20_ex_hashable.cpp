#include <string>
#include <cstddef>
#include <concepts>
using namespace std::literals;

// declaration of the concept "Hashable" which is satisfied by
// any type T such that for values a of type T,
// the epxression std::hash<T>(a) compiles and its result is 
// convertible to std::size_t
template<typename T>
concept Hashable = requires(T a) {
    { std::hash<T>{}(a) } -> std::convertible_to<std::size_t>;
};

struct meow {};

template<Hashable T>
void f(const T& val) // constrained C++20 function template
{

}

// alternative ways to apply the same constraint:
// template<typename T>
//    requires Hashable<T>
// void f(T);
//
// template<typename T>
// void f(T) requires Hashable<T>

int main() {
  f("abc"s); // OK std::string satisifes Hashable
  // f(meow{}); // error: meow does not satisfy Hashable
}

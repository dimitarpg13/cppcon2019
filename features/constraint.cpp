#include <string>
#include <cstddef>
#include <concepts>
using namespace std::literals;

// declaration of the concept "Hashable"
// any type T such that for values of type T,
// the expression std::hash<T>{}(a) compiles and its result
// is convertible to std::size_t
template<typename T>
concept Hashable = requires(T a) {
    { std::hash<T>{}(a) -> std::convertible_to<std::size_t>;
};

struct meow {};

template<Hashable T>
void f(T);

int main() {
    f("abc"s);
    //f(meow{}); // error: meaw does not satisfy the Hashable constraint
}

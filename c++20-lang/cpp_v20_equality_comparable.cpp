#include <iostream>
#include <concepts>

template <class T>
concept bool EqualityComparable() {
    return requires(T a, T b) {
        {a == b} -> Boolean; // Boolean is the concept defining a type useable in boolean context
        {a != b} -> Boolean;

    };
};

void f(const EqualityComparable auto&); // constrained function template decl

int main(const int argc, const char* const argv[]) {

   return 0;
}

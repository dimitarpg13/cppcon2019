#include <iostream>

class MyClass {
    public:
        MyClass(const MyClass&) = delete;
        MyClass(MyClass&&) = delete;

};

void foo(MyClass param) { // param is initialized by passed argument

}

MyClass bar() {
    return MyClass{};
}


int main(int argc, char* argv[]) {
  foo(MyClass{});
  MyClass x = bar();
  foo(bar());
  return 0;
}

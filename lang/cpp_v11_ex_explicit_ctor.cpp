#include <iostream>

class Foo
{
public:
  // single parameter constructor can be used as an implicity conversion
  Foo (int foo) : m_foo (foo)
  {
  }

  int GetFoo () { return m_foo; }
private:
  int m_foo; 
};

class Foo2
{
public:
  // the keyword excplicit prevents implicity conversion of arguments
  explicit Foo2(int foo) : m_foo (foo)
  {
  }

  int GetFoo () { return m_foo; }
private:
  int m_foo;
};

void DoBar (Foo foo)
{
  int i = foo.GetFoo ();
  std::cout << "Invoking DoBar (Foo foo) with value " << i << std::endl;
};

void DoBar (Foo2 foo) 
{
  int i = foo.GetFoo ();
  std::cout << "Invoking DoBar (Foo2 foo) with value " << i << std::endl;
}

int main (const int argc, const char * const argv[]) {
  DoBar(42);
  DoBar(43);
}

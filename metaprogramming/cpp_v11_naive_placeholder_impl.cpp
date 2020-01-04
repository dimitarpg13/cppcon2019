#include <iostream>

namespace placeholder_tests {

struct void_ {
  typedef void type;
};

template <int N> 
struct arg 
{
   template < typename... Args>
   struct apply
   {
      typedef void type;
   };
};


template <>
struct arg<1>
{
   template <
      class A1, typename... Args>
   struct apply
   {
      typedef A1 type; // return the first argument
   };
};
typedef arg<1> _1;

template <>
struct arg<2>
{
   template <
      class A1, class A2, typename... Args>
   struct apply
   {
      typedef A2 type; // return the second argument
   };
};
typedef arg<2> _2;


//template <>
//struct arg<>
//{
//   template <
//	  class A1,  class A2, typename... Args>
//   struct apply
//   {
//      typedef void type;
//   };   
//};



}

int main(const int argc, const char * const argv[]) {
  return 0;
}

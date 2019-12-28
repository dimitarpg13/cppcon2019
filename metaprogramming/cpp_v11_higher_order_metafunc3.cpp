#include <iostream>
#include <boost/type_traits/add_pointer.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/static_assert.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/lambda.hpp>

namespace mpl = boost::mpl;
using namespace mpl::placeholders;

template <class UnaryMetaFunctionClass, class Arg>
struct apply1
   : UnaryMetaFunctionClass::template apply<Arg>
{};

template <class F, class X>
struct twice 
   : apply1<
	    typename mpl::lambda<F>::type
      , typename apply1<
           typename mpl::lambda<F>::type
         , X
        >::type
     >
{};

struct add_pointer_f
{
   template <class T>
   struct apply : boost::add_pointer<T> {};
};

template <class X>
struct two_pointers
   : twice<typename mpl::lambda<boost::add_pointer<_1> >::type, X>
{};

int main(const int argc, const char * const argv[]) {

  BOOST_STATIC_ASSERT((
     boost::is_same<
          two_pointers<int>::type
        , int**
     >::value
  )); 

  int* x;
  twice<add_pointer_f, int>::type p = &x;
  twice<boost::add_pointer<_1>, int>::type q = &x;

  return 0;
}

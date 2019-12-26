#include <iostream>
#include <boost/type_traits/add_pointer.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/static_assert.hpp>
#include <boost/mpl/placeholders.hpp>

namespace mpl = boost::mpl;
using namespace mpl::placeholders;

template <class F, class X>
struct twice 
   : F::template apply<
	typename F::template apply<X>::type
     >
{};

struct add_pointer_f
{
   template <class T>
   struct apply : boost::add_pointer<T> {};
};

int main(const int argc, const char * const argv[]) {

  BOOST_STATIC_ASSERT((
     boost::is_same<
          twice<add_pointer_f, int>::type
        , int**
     >::value
  )); 

  return 0;
}

#include <iostream>
#include <vector>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/apply.hpp>
#include <boost/mpl/vector.hpp>
#include <boost/mpl/transform.hpp>
#include "boost/mpl/at.hpp"
#include <boost/type_traits/add_pointer.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/static_assert.hpp>

namespace mpl = boost::mpl;
using namespace mpl::placeholders;

namespace nullary_metafunc_tests {
  struct add_pointer_f 
  {
     template <class T>
     struct apply : boost::add_pointer<T> {};
  };
  typedef mpl::vector<int, char*, double&> seq;
  typedef mpl::transform<seq, boost::add_pointer<_> >::type calc_ptr_seq;

  struct int_p {
     typedef int* type;
  };

}

int main(const int argc, const char * const argv[]) {
  mpl::at_c<nullary_metafunc_tests::seq,0>::type t1;
  mpl::at_c<nullary_metafunc_tests::calc_ptr_seq,0>::type t2;
  BOOST_MPL_ASSERT(( boost::is_same< mpl::at_c<nullary_metafunc_tests::calc_ptr_seq,0>::type, int* > ));
  return 0;
}

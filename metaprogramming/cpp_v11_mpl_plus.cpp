#include <boost/static_assert.hpp>
#include <boost/mpl/plus.hpp>
#include <boost/mpl/int.hpp>
namespace mpl = boost::mpl;

BOOST_STATIC_ASSERT((
   mpl::plus<
      mpl::int_<2>
    , mpl::int_<3>
   >::type::value == 5
));

int main(const int argc, const char * const argv[]) {
   
   return 0;
}

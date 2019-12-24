#include <boost/mpl/vector.hpp>

namespace mpl = boost::mpl;
static int const five = mpl::int_<5>::value;

typedef mpl::vector<
     signed char, short, int, long> signed_types;

int main(const int argc, const char * const argv[]) {

  return 0;
}


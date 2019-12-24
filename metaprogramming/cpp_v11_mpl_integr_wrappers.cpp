#include <boost/mpl/vector_c.hpp>

namespace mpl = boost::mpl;

typedef mpl::vector_c<int,1,0,0,0,0,0,0> mass;
typedef mpl::vector_c<int,0,1,0,0,0,0,0> length; // or position
typedef mpl::vector_c<int,0,0,1,0,0,0,0> time;
typedef mpl::vector_c<int,0,0,0,1,0,0,0> charge;
typedef mpl::vector_c<int,0,0,0,0,1,0,0> temperature;
typedef mpl::vector_c<int,0,0,0,0,0,1,0> intensity;
typedef mpl::vector_c<int,0,0,0,0,0,0,1> angle;

// base dimension :       m l  t ...
typedef mpl::vector_c<int,0,1,-1,0,0,0,0> velocity; // l/t
typedef mpl::vector_c<int,0,1,-2,0,0,0,0> acceleration; // l/(t^2)
typedef mpl::vector_c<int,1,1,-1,0,0,0,0> momentum; // ml/t
typedef mpl::vector_c<int,1,1,-2,0,0,0,0> force; // ml/(t^2)

// scalar quantity
typedef mpl::vector_c<int,0,0,0,0,0,0,0> scalar;

template <class T, class Dimensions>
struct quantity
{
  explicit quantity(T x) : m_value(x)
  {}

}

int main(const int argc, const char * const argv[]) {

  return 0;
}


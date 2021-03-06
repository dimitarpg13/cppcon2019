#include <iostream>
#include <vector>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/apply.hpp>

namespace mpl = boost::mpl;
using namespace mpl::placeholders;

namespace vector_gen_tests {

// trivial std::vector generator
template <class U>
struct make_vector { typedef std::vector<U> type; };

template <class T>
using vector_of_t = typename mpl::apply<make_vector<_>, T>::type;

}

int main(const int argc, const char * const argv[]) {
  vector_gen_tests::vector_of_t<int> vec;
  vec.push_back(1);
  vec.push_back(2);
  std::cout << "vec[0] = " << vec[0] << ", vec[1] = " << vec[1] << std::endl;
  return 0;
}

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
using vector_of_t_impl1 = typename mpl::apply<make_vector<_>, T>::type;

template <class T>
using vector_of_t_impl2 = typename mpl::apply<std::vector<_>, T>::type;

}

int main(const int argc, const char * const argv[]) {
  vector_gen_tests::vector_of_t_impl1<int> vec;
  vec.push_back(1);
  vec.push_back(2);
  std::cout << "vec[0] = " << vec[0] << ", vec[1] = " << vec[1] << std::endl;
  vector_gen_tests::vector_of_t_impl2<int> vec2;
  vec2.push_back(3);
  vec2.push_back(4);
  std::cout << "vec2[0] = " << vec2[0] << ", vec2[1] = " << vec2[1] << std::endl;

  return 0;
}

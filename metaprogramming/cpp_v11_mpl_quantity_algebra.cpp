#include <iostream>
#include <boost/mpl/plus.hpp>
#include <boost/mpl/int.hpp>
#include <boost/mpl/vector_c.hpp>
#include <boost/mpl/transform.hpp>

namespace mpl = boost::mpl;
namespace physics {
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

  T value() const { return m_value; }
private:
  T m_value;

};

template <class T, class D>
quantity<T,D>
operator+(quantity<T,D> x, quantity<T,D> y)
{
   return quantity<T,D>(x.value() + y.value());
};

template <class T, class D>
quantity<T,D>
operator-(quantity<T,D> x, quantity<T,D> y)
{
  return quantity<T,D>(x.value() - y.value());
};

struct plus_f 
{
   template <class T1, class T2>
   struct apply
   {
      typedef typename mpl::plus<T1,T2>::type type;
   };
};

template <class T, class D1, class D2>
quantity<T, typename mpl::transform<D1,D2,plus_f>::type>
operator * (quantity<T,D1> x, quantity<T,D2> y) { 
   return quantity<T,  typename mpl::transform<D1,D2,plus_f>::type>(x.value() * y.value());
}

} // physics namespace

int main(const int argc, const char * const argv[]) {
  physics::quantity<float,physics::length> l1( 1.0f );
  physics::quantity<float,physics::length> l2( 2.0f );
  physics::quantity<float,physics::mass> m( 2.0f );
  auto res = l1 + l2;
  std::cout << "l1 + l2 = " << res.value() << std::endl;
  return 0;
}


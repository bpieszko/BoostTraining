#include <iostream>
#include <type_traits>
#include <boost/utility/enable_if.hpp>

template <typename T>
void print(typename boost::enable_if<std::is_integral<T>, T>::type i) {
	std::cout << "Integral: " << i << std::endl;
}

template <typename T>
void print(typename boost::enable_if<std::is_floating_point<T>, T>::type f) {
	std::cout << "Floating point: " << f << std::endl;
}

int main() {
	print<short>(1);
	print<long>(2);
	print<double>(3.15);
}
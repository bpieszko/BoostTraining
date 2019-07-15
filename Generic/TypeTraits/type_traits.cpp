#include <iostream>
#include <boost/type_traits.hpp>

using namespace boost;

int main() {
	std::cout.setf(std::ios::boolalpha);

	std::cout << is_integral<int>::value << std::endl;
	std::cout << is_floating_point<int>::value << std::endl;
	std::cout << is_arithmetic<int>::value << std::endl;
	std::cout << is_reference<int&>::value << std::endl;
}
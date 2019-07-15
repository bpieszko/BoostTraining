#include <iostream>
#include <boost/type_traits.hpp>

using namespace boost;

int main() {
	std::cout.setf(std::ios::boolalpha);

	std::cout << is_same<is_integral<int>::type, true_type>::value << std::endl;
}
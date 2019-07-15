#include <iostream>
#include <boost/type_traits.hpp>

using namespace boost;

int main() {
	std::cout.setf(std::ios::boolalpha);

	std::cout << has_plus<int>::value << std::endl;
	std::cout << has_pre_increment<int>::value << std::endl;
	std::cout << has_trivial_copy<int>::value << std::endl;
	std::cout << has_virtual_destructor<int>::value << std::endl;
}
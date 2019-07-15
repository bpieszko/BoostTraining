#include <iostream>
#include <boost/type_traits.hpp>

using namespace boost;

int main() {
	std::cout.setf(std::ios::boolalpha);

	std::cout << is_const<add_const<int>::type>::value << std::endl;
	std::cout << is_same<remove_pointer<int*>::type, int>::value << std::endl;
	std::cout << is_same<make_unsigned<int>::type, unsigned int>::value << std::endl;
	std::cout << is_same<add_rvalue_reference<int>::type, int&&>::value << std::endl;
}
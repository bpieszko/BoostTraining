#include <boost/utility/enable_if.hpp>
#include <boost/type_traits.hpp>
#include <iostream>

template <typename T>
void print_has_post_increment() {
	std::cout << std::boolalpha << boost::has_post_increment<T>::value << std::endl;
}

int main()
{
	print_has_post_increment<int>();
	print_has_post_increment<long>();
	print_has_post_increment<std::string>();
}
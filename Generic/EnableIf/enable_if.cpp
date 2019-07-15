#include <iostream>
#include <string>
#include <type_traits>
#include <boost/utility/enable_if.hpp>

template <typename T>
typename boost::enable_if<std::is_same<T, int>, T>::type create() {
	return 1;
}

template <typename T>
typename boost::enable_if<std::is_same<T, std::string>, T>::type create() {
	return "Boost";
}

int main() {
	std::cout << create<std::string>() << std::endl;
}
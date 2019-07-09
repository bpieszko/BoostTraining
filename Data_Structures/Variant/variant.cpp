#include <iostream>
#include <string>
#include <boost/variant.hpp>

template <typename T>
void cout_variant(boost::variant<double, char, std::string> t) {
	std::cout << boost::get<T>(t) << std::endl;
}

int main () {
	boost::variant<double, char, std::string> v;
	
	v = 3.14; cout_variant<double>(v);
	v = 'A'; cout_variant<char>(v);
	v = "Boost"; cout_variant<std::string>(v);

	

	return 0;
}
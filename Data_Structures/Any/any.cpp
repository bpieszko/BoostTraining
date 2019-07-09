#include <iostream>
#include <string>
#include <boost/any.hpp>

int main () {
	boost::any a = 1;
	
	std::cout << boost::any_cast<int>(a) << std::endl;
	
	a = 3.14;
	
	std::cout << boost::any_cast<double>(a) << std::endl;

	a = true;

	std::cout << std::boolalpha << boost::any_cast<bool>(a) << std::endl;

	a = std::string{"Boost"};

	std::cout << boost::any_cast<std::string>(a) << std::endl;

	try {
		boost::any a = 1;
		std::cout << boost::any_cast<float>(a) << std::endl;
	}
	catch (boost::bad_any_cast& e) {
		std::cerr << e.what() << std::endl;
	}
}
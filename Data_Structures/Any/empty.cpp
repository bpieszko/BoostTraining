#include <iostream>
#include <typeinfo>
#include <boost/any.hpp>

int main () {
	boost::any a = 1;
	if (!a.empty()) {
		const std::type_info& ti = a.type();
		std::cout << ti.name() << std::endl;
	}
	return 0;
}
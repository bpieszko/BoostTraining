#include <iostream>
#include <boost/phoenix/phoenix.hpp>

int main() {
	using namespace boost::phoenix::placeholders;
	std::cout << arg1(1, 2, 3, 4, 5) << std::endl;

	auto v = boost::phoenix::val(2);
	std::cout << v() << std::endl;
}
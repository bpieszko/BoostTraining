#include <iostream>
#include <string>
#include <boost/fusion/tuple.hpp>

using namespace boost::fusion;

int main() {
	typedef tuple<int, std::string, bool, double> tuple_type;

	tuple_type t{10, "Boost", true, 3.14};

	std::cout << get<0>(t) << std::endl;
	std::cout << get<1>(t) << std::endl;
	std::cout << std::boolalpha << get<2>(t) << std::endl;
	std::cout << get<3>(t) << std::endl;
}
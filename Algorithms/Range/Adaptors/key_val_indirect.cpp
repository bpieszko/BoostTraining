#include <iostream>
#include <iterator>
#include <utility>
#include <string>
#include <map>
#include <array>
#include <boost/range/algorithm.hpp>
#include <boost/range/adaptors.hpp>

int main () {
	std::array<int, 3> a{{0, 1, 2}};
	std::map<std::string, int*> m;
	m.insert(std::make_pair("a", &a[0]));
	m.insert(std::make_pair("b", &a[1]));
	m.insert(std::make_pair("c", &a[2]));

	boost::copy(
		boost::adaptors::keys(m),
		std::ostream_iterator<std::string>{std::cout, ","}
	);
	
	std::cout << std::endl;

	boost::copy(
		boost::adaptors::indirect(boost::adaptors::values(m)),
		std::ostream_iterator<int>{std::cout, ","}
	);
}
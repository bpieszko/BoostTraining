#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <boost/algorithm/hex.hpp>

using namespace boost::algorithm;

int main () {
	std::vector<char> v{'C', '+', '+'};
	hex(v, std::ostream_iterator<char>{std::cout, ""});
	std::cout << std::endl;

	std::string s = "C++";
	std::cout << hex(s) << std::endl;

	std::vector<char> w{'4', '3', '2', 'b', '2', 'b'};
	unhex(w, std::ostream_iterator<char>{std::cout, ""});
	std::cout << std::endl;

	std::string t = "432b2b";
	std::cout << unhex(t) << std::endl;

	return 0;
}
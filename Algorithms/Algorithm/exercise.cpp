#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <boost/algorithm/cxx11/iota.hpp>
#include <boost/algorithm/hex.hpp>

using namespace boost::algorithm;

int main () {
	std::vector<int> v;
	iota_n(std::back_inserter(v), 51, 6);

	unhex(v, std::ostream_iterator<char>{std::cout, ""});
	std::cout << std::endl;
}
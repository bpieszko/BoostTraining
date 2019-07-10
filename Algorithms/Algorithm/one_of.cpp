#include <iostream>
#include <array>
#include <boost/algorithm/cxx11/one_of.hpp>

using namespace boost::algorithm;

int main () {
	std::array<int, 6> a{0, 5, 2, 4, 4, 3};

	auto predicate = [](int i) { return i == 4; };

	std::cout.setf(std::ios::boolalpha);

	std::cout << one_of(a.begin(), a.end(), predicate) << std::endl;
	std::cout << one_of_equal(a.begin(), a.end(), 4) << std::endl;

	return 0;
}
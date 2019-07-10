#include <iostream>
#include <iterator>
#include <vector>
#include <boost/range/algorithm.hpp>
#include <boost/range/adaptors.hpp>
#include <boost/algorithm/cxx11/iota.hpp>

using namespace boost::algorithm;

int main () {
	std::vector<int> a;
	iota_n(std::back_inserter(a), 0, 100);

	boost::copy(
		boost::adaptors::filter(
			a,
			[](int i) { return i % 2; }
		),
		std::ostream_iterator<int>{std::cout, " "}
	);
	std::cout << std::endl;

	return 0;
}
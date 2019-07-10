#include <iostream>
#include <boost/range/algorithm.hpp>
#include <boost/range/irange.hpp>

int main() {
	boost::integer_range<int> ir = boost::irange(0, 3);
	boost::copy(
		ir,
		std::ostream_iterator<int>{std::cout, ","}
	);
	return 0;
}
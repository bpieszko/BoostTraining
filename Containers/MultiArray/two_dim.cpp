#include <iostream>
#include <cstring>
#include <algorithm>
#include <boost/multi_array.hpp>

int main () {
	boost::multi_array<char, 2> a{boost::extents[2][6]};

	typedef boost::multi_array<char, 2>::array_view<1>::type array_view;
	typedef boost::multi_array_types::index_range range;

	array_view view = a[boost::indices[0][range{0, 5}]];

	std::memcpy(view.origin(), "tsooB", 6);
	std::reverse(view.begin(), view.end());

	std::cout << view.origin() << std::endl;

	boost::multi_array<char, 2>::reference subarray = a[1];
	std::memcpy(subarray.origin(), "C++", 4);

	std::cout << subarray.origin() << std::endl;

	return 0;
}
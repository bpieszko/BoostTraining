#include <iostream>
#include <array>
#include <deque>
#include <iterator>
#include <boost/range/algorithm_ext.hpp>

int main () {
	std::array<int, 6> a{{0, 1, 2, 3, 4, 5}};
	std::cout << std::boolalpha << boost::is_sorted(a) << std::endl;
	
	std::deque<int> d;
	boost::push_back(d, a);
	boost::remove_erase(d, 2);
	boost::copy_n(d, 3, std::ostream_iterator<int>{std::cout, ","});
	
	return 0;
}
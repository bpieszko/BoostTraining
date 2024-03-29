#include <iostream>
#include <algorithm>
#include <vector>
#include <boost/phoenix/phoenix.hpp>

bool is_odd_function(int i) { return i % 2; }

BOOST_PHOENIX_ADAPT_FUNCTION(bool, is_odd, is_odd_function, 1)

int main() {
	std::vector<int> v{1, 2, 3, 4, 5};

	using namespace boost::phoenix::placeholders;
	std::cout << std::count_if(v.begin(), v.end(), is_odd(arg1));
}
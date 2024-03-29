#include <iostream>
#include <algorithm>
#include <vector>
#include <boost/phoenix/phoenix.hpp>

bool is_odd(int i) { return i % 2; }

int main() {
	std::vector<int> v{1, 2, 3, 4, 5};

	using namespace boost::phoenix;
	using namespace boost::phoenix::placeholders;
	std::cout << std::count_if(v.begin(), v.end(), bind(is_odd, arg1)) << std::endl;
}
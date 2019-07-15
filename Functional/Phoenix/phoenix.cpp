#include <iostream>
#include <vector>
#include <algorithm>
#include <boost/phoenix/phoenix.hpp>

bool is_odd(int i) { return i % 2; }

int main () {
	std::vector<int> v{1, 2, 3, 4, 5};

	std::cout << std::count_if(v.begin(), v.end(), is_odd) << std::endl;

	auto lambda = [](int i) { return i % 2; };
	std::cout << std::count_if(v.begin(), v.end(), lambda) << std::endl;

	using namespace boost::phoenix::placeholders;
	auto phoenix = arg1 % 2;
	std::cout << std::count_if(v.begin(), v.end(), phoenix) << std::endl;
}
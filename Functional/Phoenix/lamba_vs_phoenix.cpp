#include <iostream>
#include <algorithm>
#include <vector>
#include <boost/phoenix/phoenix.hpp>

int main() {
	std::vector<int> v{1, 2, 3, 4, 5};

	auto lambda = [](int i){ return i % 2; };
	std::cout << std::count_if(v.begin(), v.end(), lambda) << std::endl;

	std::vector<long> v2;
	v2.insert(v2.begin(), v.begin(), v.end());

	using namespace boost::phoenix::placeholders;
	auto phoenix = arg1 % 2;

	std::cout << std::count_if(v.begin(), v.end(), phoenix) << std::endl;
	std::cout << std::count_if(v2.begin(), v2.end(), phoenix) << std::endl;
}
#include <iostream>
#include <vector>
#include <boost/algorithm/cxx14/equal.hpp>
#include <boost/algorithm/cxx14/mismatch.hpp>

using namespace boost::algorithm;

int main () {
	std::vector<int> v{1, 2};
	std::vector<int> w{1, 2, 3};

	std::cout.setf(std::ios::boolalpha);

	std::cout << equal(v.begin(), v.end(), w.begin(), w.end()) << std::endl;

	auto pr = mismatch(v.begin(), v.end(), w.begin(), w.end());
	if (pr.first != v.end())
		std::cout << *pr.first << std::endl;
	if (pr.second != w.end())
		std::cout << *pr.second << std::endl;

	return 0;
}
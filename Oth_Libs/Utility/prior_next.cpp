#include <boost/next_prior.hpp>
#include <array>
#include <algorithm>
#include <iostream>

int main() {
	std::array<char, 4> a{{'a', 'b', 'c', 'd'}};

	auto it = std::find(a.begin(), a.end(), 'b');
	auto prior = boost::prior(it, 2);
	auto next = boost::next(it);

	std::cout << *prior << std::endl;
	std::cout << *it << std::endl;
	std::cout << *next << std::endl;
}
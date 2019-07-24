#include <iostream>
#include <boost/accumulators/accumulators.hpp>
#include <boost/accumulators/statistics.hpp>

using namespace boost::accumulators;

int main() {
	accumulator_set<int, features<tag::count>> acc;

	acc(-6);
	acc(4);
	acc(9);
	acc(4);

	std::cout << count(acc) << std::endl;
}
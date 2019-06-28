#include <iostream>
#include <boost/shared_array.hpp>

int main () {
	boost::shared_array<int> p1{new int[10]};
	{
		boost::shared_array<int> p2{p1};
		p2[0] = 1;
	}
	std::cout << p1[0] << std::endl;

	return 0;
}
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <boost/function.hpp>

int main() {
	boost::function<int(const char *)> f = std::atoi;
	std::cout << f("42") << std::endl;

	f = std::strlen;
	std::cout << f("42") << std::endl;
}
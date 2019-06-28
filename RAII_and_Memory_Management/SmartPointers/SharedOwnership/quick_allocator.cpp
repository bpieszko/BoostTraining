#include <iostream>
#include <ctime>
#include <boost/shared_ptr.hpp>

int main () {
	boost::shared_ptr<int> p1;
	
	std::time_t then = std::time(nullptr);
	for (int i = 0; i < 1e8; ++i) {
		p1.reset(new int{1});
	}
	std::time_t now = std::time(nullptr);
	
	std::cout << now - then << std::endl;

	return 0;
}
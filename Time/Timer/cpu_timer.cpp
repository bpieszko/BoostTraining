#include <iostream>
#include <cmath>
#include <boost/timer/timer.hpp>

using namespace boost::timer;

int main() {
	cpu_timer timer;

	for(int i = 0; i < 1e8; ++i) {
		std::pow(1.234, i);
	}

	std::cout << timer.format() << std::endl;
}
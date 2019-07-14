#include <boost/timer/timer.hpp>
#include <iostream>
#include <cmath>

using namespace boost::timer;

int main() {
	cpu_timer timer;

	for (int i = 0; i < 1e7; ++i)
		std::pow(1.234, i);

	cpu_times times = timer.elapsed();

	std::cout << times.wall << std::endl;
	std::cout << times.user << std::endl;
	std::cout << times.system << std::endl;
}
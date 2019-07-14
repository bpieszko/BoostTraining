#include <iostream>
#include <cmath>
#include <boost/timer/timer.hpp>

using namespace boost::timer;

int main() {
	auto f = [](cpu_timer& timer){
		for (int i = 0; i < 1e7; ++i)
			std::pow(1.134, i);
		std::cout << timer.format() << std::endl;
	};

	cpu_timer timer;
	f(timer);
	timer.stop();
	f(timer);
	timer.resume();
	f(timer);
}
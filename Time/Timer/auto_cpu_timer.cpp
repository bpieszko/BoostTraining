#include <cmath>
#include <boost/timer/timer.hpp>

using namespace boost::timer;

int main() {
	auto_cpu_timer timer;

	for (int i = 0; i < 1e7; ++i) {
		std::pow(1.234, i);
	}
}
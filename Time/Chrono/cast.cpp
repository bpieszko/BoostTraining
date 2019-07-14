#include <iostream>
#include <boost/chrono.hpp>

using namespace boost::chrono;

int main() {
	process_real_cpu_clock::time_point p = process_real_cpu_clock::now();
	std::cout << p << std::endl;
	std::cout << time_point_cast<minutes>(p) << std::endl;
}
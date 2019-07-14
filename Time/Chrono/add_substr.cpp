#include <iostream>
#include <boost/chrono.hpp>

using namespace boost::chrono;

int main() {
	process_real_cpu_clock::time_point p = process_real_cpu_clock::now();
	
	std::cout << p << std::endl;
	std::cout << p - nanoseconds{1} << std::endl;
	std::cout << p + milliseconds{1} << std::endl;
	std::cout << p + seconds{1} << std::endl;
	std::cout << p + minutes{1} << std::endl;
	std::cout << p + hours{1} << std::endl;
}
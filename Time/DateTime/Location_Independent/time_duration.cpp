#include <iostream>
#include <boost/date_time/posix_time/posix_time.hpp>

using namespace boost::posix_time;

int main() {
	time_duration td{16, 30, 0};
	
	std::cout << td.hours() << std::endl;
	std::cout << td.minutes() << std::endl;
	std::cout << td.seconds() << std::endl;
	std::cout << td.total_seconds() << std::endl;
}
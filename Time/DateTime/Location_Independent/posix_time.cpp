#include <iostream>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

using namespace boost::posix_time;
using namespace boost::gregorian;

int main() {
	ptime pt{date{2014, 5, 12}, time_duration{12, 0, 0}};
	date d = pt.date();
	std::cout << d << std::endl;
	time_duration td = pt.time_of_day();
	std::cout << td << std::endl;
}
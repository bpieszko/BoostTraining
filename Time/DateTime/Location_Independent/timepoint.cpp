#include <iostream>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

using namespace boost::posix_time;

int main() {
	ptime pt = second_clock::universal_time();
	std::cout << pt.date() << std::endl;
	std::cout << pt.time_of_day() << std::endl;

	pt = from_iso_string("20140512T120000");
	std::cout << pt.date() << std::endl;
	std::cout << pt.time_of_day() << std::endl;
}
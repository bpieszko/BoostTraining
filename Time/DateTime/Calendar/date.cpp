#include <iostream>
#include <boost/date_time/gregorian/gregorian.hpp>

int main() {
	boost::gregorian::date d{2014, 1, 31};
	std::cout << d.year() << std::endl;
	std::cout << d.month() << std::endl;
	std::cout << d.day() << std::endl;
	std::cout << d.day_of_week() << std::endl;
	std::cout << d.end_of_month() << std::endl;
}
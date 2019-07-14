#include <iostream>
#include <boost/date_time/gregorian/gregorian.hpp>

using namespace boost::gregorian;

int main () {
	date d = day_clock::universal_day();

	auto print_date = [](const date& d) {
		std::cout << d.year() << std::endl;
		std::cout << d.month() << std::endl;
		std::cout << d.day() << std::endl;
	};

	print_date(d);

	d = date_from_iso_string("20140131");

	print_date(d);
}
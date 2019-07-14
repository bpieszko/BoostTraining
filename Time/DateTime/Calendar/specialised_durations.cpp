#include <iostream>
#include <boost/date_time/gregorian/gregorian.hpp>

using namespace boost::gregorian;

int main() {
	date_duration dd{4};
	std::cout << dd.days() << std::endl;

	weeks ws{4};
	std::cout << ws.days() << std::endl;

	months ms{4};
	std::cout << ms.number_of_months() << std::endl;

	years ys{4};
	std::cout << ys.number_of_years() << std::endl;
}
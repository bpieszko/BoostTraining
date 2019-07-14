#include <iostream>
#include <boost/date_time/gregorian/gregorian.hpp>

using namespace boost::gregorian;

int main () {
	date d1{2014, 1, 31};
	date d2{2019, 07, 14};
	
	date_duration dd = d2 - d1;

	std::cout << dd.days() << std::endl;
}
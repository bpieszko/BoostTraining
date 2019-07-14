#include <iostream>
#include <boost/date_time/gregorian/gregorian.hpp>

using namespace boost::gregorian;

int main () {
	date d1{2014, 1, 1};
	date d2{2014, 2, 28};

	date_period dp{d1, d2};

	date_duration dd = dp.length();
	std::cout << dd << std::endl;

	std::cout.setf(std::ios::boolalpha);

	std::cout << dp.contains(d1) << std::endl;
	std::cout << dp.contains(d2) << std::endl;

	return 0;
}
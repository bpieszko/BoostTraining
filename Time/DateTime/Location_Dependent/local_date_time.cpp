#include <iostream>
#include <boost/date_time/local_time/local_time.hpp>

using namespace boost::local_time;
using namespace boost::posix_time;
using namespace boost::gregorian;

int main() {
	time_zone_ptr tz{new posix_time_zone{"CET+2"}};
	ptime pt{date{2014, 5, 12}, time_duration{12, 0, 0}};
	local_date_time dt{pt,tz};

	std::cout << dt.utc_time() << std::endl;
	std::cout << dt << std::endl;
	std::cout << dt.local_time() << std::endl;
	std::cout << dt.zone_name() << std::endl;
}
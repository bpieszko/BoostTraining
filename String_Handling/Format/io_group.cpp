#include <iostream>
#include <boost/format.hpp>

int main () {
	std::cout << boost::format{"%1% %2% %1%"} %
		boost::io::group(std::showpos, 1) % 2 << std::endl;
	return 0;
}
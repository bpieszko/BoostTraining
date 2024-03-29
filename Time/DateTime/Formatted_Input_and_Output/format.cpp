#include <iostream>
#include <locale>
#include <boost/date_time/gregorian/gregorian.hpp>

using namespace boost::gregorian;

int main() {
	date d{2014, 5, 12};
	date_facet* df = new date_facet{"%A, %d %B %Y"};
	std::cout.imbue(std::locale(std::cout.getloc(), df));
	std::cout << d << std::endl;
}
#include <iostream>
#include <boost/regex.hpp>
#include <boost/iostreams/device/array.hpp>
#include <boost/iostreams/filtering_stream.hpp>
#include <boost/iostreams/filter/regex.hpp>

using namespace boost::iostreams;

int main () {
	char buffer[16];

	array_sink sink{buffer};
	filtering_ostream os;
	os.push(regex_filter{boost::regex{"Bo+st"}, "C++"});
	os.push(sink);
	os << "Boost" << std::flush;
	os.pop();
	std::cout.write(buffer, 3);

	return 0;
}
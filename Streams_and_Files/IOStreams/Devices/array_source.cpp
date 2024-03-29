#include <iostream>
#include <string>
#include <boost/iostreams/device/array.hpp>
#include <boost/iostreams/stream.hpp>

using namespace boost::iostreams;

int main () {
	char buffer[16];
	array_sink sink{buffer};
	stream<array_sink> os{sink};
	os << "Boost" << std::endl;

	array_source source{buffer};
	stream<array_source> is{source};
	std::string s;

	is >> s;

	std::cout << s << std::endl;

	return 0;
}
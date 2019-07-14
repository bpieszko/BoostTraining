#include <iostream>
#include <boost/iostreams/stream.hpp>
#include <boost/iostreams/device/array.hpp>

using namespace boost::iostreams;

int main () {
	char buffer[16];
	
	array_sink sink{buffer};
	stream<array_sink> os{sink};
	os << "Hello world!" << std::endl;

	array_source source{buffer};
	stream<array_source> is{buffer};
	std::string message;
	std::getline(is, message);
	std::cout << message << std::endl;

	return 0;
}
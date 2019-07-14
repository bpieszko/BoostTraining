#include <iostream>
#include <boost/iostreams/stream.hpp>
#include <boost/iostreams/device/file.hpp>

using namespace boost::iostreams;

int main () {
	file_source f{"main.cpp"};
	if (f.is_open()) {
		stream<file_source> is{f};
		std::cout << is.rdbuf() << std::endl;
		f.close();
	}
}
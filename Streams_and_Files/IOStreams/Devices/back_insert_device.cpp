#include <iostream>
#include <string>
#include <vector>
#include <boost/iostreams/stream.hpp>
#include <boost/iostreams/device/array.hpp>
#include <boost/iostreams/device/back_inserter.hpp>

using namespace boost::iostreams;

int main () {
	std::vector<char> v;
	back_insert_device<std::vector<char>> sink{v};
	stream<back_insert_device<std::vector<char>>> os{sink};

	os << "Boost" << std::endl;

	array_source source{v.data(), v.size()};
	stream<array_source> is{source};
	std::string s;
	is >> s;
	std::cout << s << std::endl;

	
	return 0;
}
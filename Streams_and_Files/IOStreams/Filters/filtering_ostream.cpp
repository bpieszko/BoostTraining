#include <iostream>
#include <boost/iostreams/filter/counter.hpp>
#include <boost/iostreams/device/array.hpp>
#include <boost/iostreams/filtering_stream.hpp>

using namespace boost::iostreams;

int main () {
	char buffer[16];
	
	array_sink sink{buffer};
	filtering_ostream os;
	
	os.push(counter{});
	os.push(sink);

	os << "Boost" << std::flush;
	os.pop();

	counter* c = os.component<counter>(0);

	std::cout << c->characters() << std::endl;
	std::cout << c->lines() << std::endl;
	return 0;
}
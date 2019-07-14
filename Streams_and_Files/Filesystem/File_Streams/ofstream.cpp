#include <iostream>
#include <boost/filesystem/fstream.hpp>

using namespace boost::filesystem;

int main() {
	path p{"test.txt"};
	ofstream ofs{p};
	ofs << "Hello world" << std::endl;

	return 0;
}
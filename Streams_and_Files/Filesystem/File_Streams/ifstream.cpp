#include <iostream>
#include <boost/filesystem/fstream.hpp>

using namespace boost::filesystem;

int main () {
	path p{"test.txt"};
	ifstream ifs{p};
	
	std::string s;
	std::getline(ifs, s);
	std::cout << s << std::endl;
}
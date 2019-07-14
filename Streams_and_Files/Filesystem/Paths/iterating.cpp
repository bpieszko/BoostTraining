#include <iostream>
#include <boost/filesystem.hpp>

using namespace boost::filesystem;

int main () {
	path p{"/home/bpieszko/Desktop/file.txt"};
	for (const path &pp : p) 
		std::cout << pp << std::endl;
}
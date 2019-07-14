#include <iostream>
#include <ctime>
#include <boost/filesystem.hpp>

using namespace boost::filesystem;

int main () {
	path p{"/home/bpieszko/My/Git/bpieszko/BoostTraining/Streams_and_Files/Filesystem/Files_and_Directories/last_write_time.cpp"};
	try {
		std::time_t t = last_write_time(p);
		std::cout << std::ctime(&t) << std::endl;
	}
	catch (filesystem_error& e) {
		std::cerr << e.what() << std::endl;
	}
}

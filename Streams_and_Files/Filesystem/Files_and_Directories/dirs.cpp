#include <iostream>
#include <boost/filesystem.hpp>

using namespace boost::filesystem;

int main() {
	path p{"/home/bpieszko/My/Git/bpieszko/BoostTraining/Streams_and_Files/Filesystem/Files_and_Directories/test"};
	try {
		if(create_directory(p)) {
			rename(p, "/home/bpieszko/My/Git/bpieszko/BoostTraining/Streams_and_Files/Filesystem/Files_and_Directories/test2");
			boost::filesystem::remove("/home/bpieszko/My/Git/bpieszko/BoostTraining/Streams_and_Files/Filesystem/Files_and_Directories/test2");
		}
	}
	catch (filesystem_error& e) {
		std::cerr << e.what() << std::endl;
	}
}
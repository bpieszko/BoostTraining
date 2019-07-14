#include <iostream>
#include <boost/filesystem.hpp>

using namespace boost::filesystem;

int main () {
	path p{"/home/bpieszko/My/Git/bpieszko/BoostTraining/Streams_and_Files/Filesystem/Files_and_Directories/file_size.cpp"};
	boost::system::error_code ec;
	boost::uintmax_t filesize = file_size(p, ec);
	if (!ec)
		std::cout << filesize << std::endl;
	else
		std::cout << ec << std::endl;
}
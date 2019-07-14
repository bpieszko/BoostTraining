#include <iostream>
#include <boost/filesystem.hpp>

using namespace boost::filesystem;

int main() {
	path p{"/"};
	
	try {
		space_info s = space(p);
		std::cout << s.capacity << std::endl;
		std::cout << s.free << std::endl;
		std::cout << s.available << std::endl;
	}
	catch (filesystem_error& e) {
		std::cerr << e.what() << std::endl;
	}
}
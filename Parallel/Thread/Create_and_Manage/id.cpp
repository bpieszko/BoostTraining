#include <iostream>
#include <boost/thread.hpp>

int main() {
	std::cout << boost::this_thread::get_id() << std::endl;
	std::cout << boost::thread::hardware_concurrency() << std::endl;
}
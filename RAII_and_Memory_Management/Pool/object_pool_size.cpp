#include <iostream>
#include <boost/pool/object_pool.hpp>

int main () {
	boost::object_pool<int> pool{32, 0};
	pool.construct();
	std::cout << pool.get_next_size() << std::endl;
	pool.set_next_size(8);
	return 0;
}
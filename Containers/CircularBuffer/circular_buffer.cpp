#include <iostream>
#include <boost/circular_buffer.hpp>

int main () {
	boost::circular_buffer<int> cb{3};

	std::cout << cb.capacity() << std::endl;
	std::cout << cb.size() << std::endl;

	cb.push_back(0);
	cb.push_back(1);
	cb.push_back(2);

	std::cout << cb.size() << std::endl;

	cb.push_back(3);
	cb.push_back(4);

	std::cout << cb.size() << std::endl;

	for (auto i : cb) {
		std::cout << i << std::endl;
	}

	return 0;
}
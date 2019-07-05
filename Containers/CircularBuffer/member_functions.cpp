#include <iostream>
#include <boost/circular_buffer.hpp>

int main () {
	boost::circular_buffer<int> cb{3};

	cb.push_back(0);
	cb.push_back(1);
	cb.push_back(2);
	cb.push_back(3);

	std::cout << std::boolalpha << cb.is_linearized() << std::endl;

	boost::circular_buffer<int>::array_range ar1, ar2;

	ar1 = cb.array_one();
	ar2 = cb.array_two();
	std::cout << ar1.second << ";" << ar2.second << std::endl;

	for (auto i : cb) {
		std::cout << i << ", ";
	}
	std::cout << std::endl;

	cb.linearize();

	ar1 = cb.array_one();
	ar2 = cb.array_two();

	std::cout << ar1.second << ";" << ar2.second << std::endl;

	return 0;
}
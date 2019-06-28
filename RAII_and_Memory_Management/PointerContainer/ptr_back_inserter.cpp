#include <iostream>
#include <algorithm>
#include <array>
#include <boost/ptr_container/ptr_vector.hpp>
#include <boost/ptr_container/ptr_inserter.hpp>

int main () {
	boost::ptr_vector<int> pv;
	std::array<int, 3> ar{{1, 2, 3}};

	std::copy(ar.begin(), ar.end(), boost::ptr_container::ptr_back_inserter(pv));

	std::cout << pv.size() << std::endl;
	for (auto & i : pv) {
		std::cout << i << " ";
	}
	std::cout << std::endl;

	return 0;
}
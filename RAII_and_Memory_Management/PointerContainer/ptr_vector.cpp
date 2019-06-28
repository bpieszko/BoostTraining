#include <iostream>
#include <boost/ptr_container/ptr_vector.hpp>

int main () {
	boost::ptr_vector<int> v;
	
	v.push_back(new int{2});
	v.push_back(new int{4});
	
	std::cout << v.back() << std::endl;

	return 0;
}
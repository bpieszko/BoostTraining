#include <vector>
#include <algorithm>
#include <iterator>
#include <boost/assign.hpp>
#include <iostream>

using namespace boost::assign;

int main()
{
	std::vector<int> v = list_of(1)(2)(3);
	std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout));
	boost::assign::push_back(v)(4)(5)(6);
	std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout));
}
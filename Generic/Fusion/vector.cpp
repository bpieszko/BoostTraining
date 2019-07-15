#include <iostream>
#include <string>
#include <boost/fusion/container.hpp>
#include <boost/fusion/sequence.hpp>
#include <boost/mpl/int.hpp>

using namespace boost::fusion;

int main() {
	typedef vector<int, std::string, bool, double> vector_type;

	vector_type v{10, "Boost", true, 3.14};
	std::cout << at<boost::mpl::int_<0>>(v) << std::endl;

	auto v2 = push_back(v, 'X');
	std::cout << size(v) << std::endl;
	std::cout << size(v2) << std::endl;
	std::cout << back(v2) << std::endl;
}
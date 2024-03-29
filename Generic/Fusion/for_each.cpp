#include <iostream>
#include <string>
#include <boost/fusion/tuple.hpp>
#include <boost/fusion/algorithm.hpp>

using namespace boost::fusion;

struct print {
	template <typename T>
	void operator()(const T& t) const {
		std::cout << std::boolalpha << t << std::endl;
	}
};

int main() {
	typedef tuple<int, std::string, bool, double> tuple_type;
	tuple_type t{10, "Boost", true, 3.14};
	for_each(t, print{});
}
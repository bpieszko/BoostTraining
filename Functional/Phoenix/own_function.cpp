#include <iostream>
#include <algorithm>
#include <vector>
#include <boost/phoenix/phoenix.hpp>

struct is_odd_impl
{
	typedef bool result_type;

	template <typename T>
	bool operator()(T t) const {
		return t % 2;
	}
};

boost::phoenix::function<is_odd_impl> is_odd;

int main() {
	std::vector<int> v{1, 2, 3, 4, 5};

	using namespace boost::phoenix::placeholders;
	std::cout << std::count_if(v.begin(), v.end(), is_odd(arg1));
}
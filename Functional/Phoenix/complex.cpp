#include <iostream>
#include <algorithm>
#include <vector>
#include <boost/phoenix/phoenix.hpp>

int main() {
	std::vector<int> v{1, 2, 3, 4, 5};

	using namespace boost::phoenix;
	using namespace boost::phoenix::placeholders;

	int count = 0;
	std::for_each(v.begin(), v.end(), if_(arg1 > 0 && arg1 % 2)
	[
		++ref(count)
	]);

	std::cout << count << std::endl;
}
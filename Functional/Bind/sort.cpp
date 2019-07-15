#include <iostream>
#include <vector>
#include <algorithm>
#include <boost/bind.hpp>

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	std::vector<int> v{1, 3, 2};
	std::sort(v.begin(), v.end(), boost::bind(cmp, _2, _1));

	for (int i : v) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
}
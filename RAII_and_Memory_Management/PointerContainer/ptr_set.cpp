#include <iostream>
#include <functional>
#include <memory>
#include <set>
#include <boost/ptr_container/ptr_set.hpp>
#include <boost/ptr_container/indirect_fun.hpp>

int main () {
	boost::ptr_set<int> s;
	s.insert(new int{2});
	s.insert(new int{4});
	s.insert(new int{2});

	std::cout << *s.begin() << std::endl;
	for (auto & i : s) {
		std::cout << i << std::endl;
	}

	std::set<std::unique_ptr<int>, boost::indirect_fun<std::less<int>>> s2;
	s2.insert(std::make_unique<int>(2));
	s2.insert(std::make_unique<int>(4));

	std::cout << **s2.begin() << std::endl;
	for (auto & i : s2) {
		std::cout << *i << std::endl;
	}

	return 0;
}
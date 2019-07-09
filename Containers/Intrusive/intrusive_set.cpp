#include <iostream>
#include <string>
#include <utility>
#include <boost/intrusive/set.hpp>

using namespace boost::intrusive;

struct animal {
	std::string name;
	int legs;
	set_member_hook<> set_hook;
	animal(std::string n, int l) : name(std::move(n)), legs{l} {}
	bool operator< (const animal& a) const { return legs < a.legs; }
};

int main () {
	animal a1{"cat", 4};
	animal a2{"shark", 0};
	animal a3{"spider", 8};

	set<
		animal,
		member_hook<
			animal,
			set_member_hook<>,
			&animal::set_hook
		>
	> animals;

	animals.insert(a1);
	animals.insert(a2);
	animals.insert(a3);

	for (const auto& a : animals) {
		std::cout << a.name << std::endl;
	}

	return 0;
}
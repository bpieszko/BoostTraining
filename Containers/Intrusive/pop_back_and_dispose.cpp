#include <iostream>
#include <string>
#include <utility>
#include <boost/intrusive/list.hpp>

using namespace boost::intrusive;

struct animal : public list_base_hook<>
{
	std::string name;
	int legs;
	animal(std::string n, int l) : name(std::move(n)), legs{l} {}
};

int main () {
	animal a1{"cat", 4};
	animal a2{"shark", 0};
	animal* a3 = new animal{"spider", 8};

	list<animal> animals;

	animals.push_back(a1);
	animals.push_back(a2);
	animals.push_back(*a3);

	animals.pop_back_and_dispose([](animal* a){ delete a; });

	for (const animal& a : animals) {
		std::cout << a.name << std::endl;
	}

	return 0;
}
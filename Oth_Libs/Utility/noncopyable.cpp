#include <boost/noncopyable.hpp>
#include <string>
#include <utility>
#include <iostream>

struct animal : boost::noncopyable
{
	std::string name;
	int legs;

	animal(std::string n, int l) : name{std::move(n)}, legs{l} {}
};

void print(const animal& a) {
	std::cout << a.name << " " << a.legs << std::endl;
}

int main() {
	animal a{"cat", 4};
	print(a);
}
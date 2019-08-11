#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <iostream>

int main() {
	boost::uuids::random_generator gen;
	boost::uuids::uuid id = gen();
	std::cout << id << std::endl;

	std::cout << id.size() << std::endl;
	std::cout << std::boolalpha << id.is_nil() << std::endl;
	std::cout << id.variant() << std::endl;
	std::cout << id.version() << std::endl;
}

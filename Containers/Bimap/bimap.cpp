#include <iostream>
#include <string>
#include <boost/bimap.hpp>

int main () {
	boost::bimap<std::string, int> animals;

	animals.insert({"cat", 4});
	animals.insert({"shark", 0});
	animals.insert({"spider", 8});

	std::cout << animals.left.count("cat") << std::endl;
	std::cout << animals.right.count(8) << std::endl;

	return 0;
}
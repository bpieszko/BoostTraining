#include <iostream>
#include <string>
#include <boost/bimap.hpp>

int main () {
	boost::bimap<std::string, int> animals;
	
	animals.insert({"cat", 4});
	animals.insert({"shark", 0});
	animals.insert({"spider", 8});

	for (auto it = animals.begin(); it != animals.end(); it++) {
		std::cout << it->left << " has " << it->right << " legs" << std::endl;
	}

	return 0;
}
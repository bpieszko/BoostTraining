#include <iostream>
#include <boost/property_tree/ptree.hpp>

using boost::property_tree::ptree;

int main () {
	ptree pt;
	pt.put("C:.Windows.System", "20 files");

	ptree& c = pt.get_child("C:");
	ptree& windows = c.get_child("Windows");
	ptree& system = windows.get_child("System");

	std::cout << system.get_value<std::string>() << std::endl;

	return 0;
}
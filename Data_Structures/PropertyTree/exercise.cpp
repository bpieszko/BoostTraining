#include <iostream>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

using namespace boost::property_tree;

struct string_to_bool {
	typedef std::string internal_type;
	typedef bool external_type;

	boost::optional<bool> get_value(const std::string& s) {
		return (s == "true");
	}
};

int main () {
	ptree pt;
	json_parser::read_json("ex.json", pt);

	string_to_bool s_to_b;
	bool log_all = pt.get<bool>(ptree::path_type{"log.all"}, s_to_b);

	ptree& animals = pt.get_child(ptree::path_type{"animals"});

	for (const std::pair<std::string, ptree>& p : animals) {
		std::cout << p.second.get_child("name").get_value<std::string>() << std::endl;

		if (log_all) {
			std::cout << p.second.get_child("legs").get_value<int>() << std::endl;
			std::cout << std::boolalpha << p.second.get<bool>(ptree::path_type{"has_tail"}, s_to_b) << std::endl;
		}
	}

	return 0;
}
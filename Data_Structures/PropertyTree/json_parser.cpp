#include <iostream>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

using namespace boost::property_tree;

int main () {
	ptree pt;
	pt.put("C:.Windows.System", "20 files");
	pt.put("C:.Windows.Cursors", "50 files");

	json_parser::write_json("file.json", pt);
	
	ptree pt2;
	json_parser::read_json("file.json", pt2);

	// ini_parser
	// xml_parser
	// info_parser

	std::cout << std::boolalpha << (pt == pt2) << std::endl;

	return 0;
}
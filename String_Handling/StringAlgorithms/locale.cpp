#include <iostream>
#include <string>
#include <locale>
#include <boost/algorithm/string.hpp>

using namespace boost::algorithm;

int main () {
	std::string s{"Boost C++ k\xfct\xfcphaneleri"};
	
	std::string su1{to_upper_copy(s)};
	std::string sl1{to_lower_copy(s, std::locale{"tr_TR"})};

	std::locale::global(std::locale{"tr_TR"});

	std::cout << su1 << std::endl << sl1 << std::endl;
}
#include <iostream>
#include <string>
#include <boost/regex.hpp>
#include <boost/range/algorithm.hpp>
#include <boost/range/adaptors.hpp>

int main () {
	std::string s = "The Boost C++ Libraries";
	boost::regex expr{"[\\w+]+"};
	boost::copy(
		boost::adaptors::tokenize(
			s,
			expr,
			0,
			boost::regex_constants::match_default //match_perl
		),
		std::ostream_iterator<std::string>{std::cout, ","}
	);
	return 0;
}
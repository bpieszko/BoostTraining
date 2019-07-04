#include <iostream>
#include <string>
#include <boost/tokenizer.hpp>

int main () {
	typedef boost::tokenizer <
		boost::char_separator<wchar_t>,
		std::wstring::const_iterator,
		std::wstring
	> tokenizer;

	std::wstring s{L"Boost C++ Libraries"};
	boost::char_separator<wchar_t> sep{L""};
	tokenizer tok{s, sep};

	for (const auto& token : tok) {
		std::wcout << token << std::endl;
	}
	return 0;
}
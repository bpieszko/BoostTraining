#include <iostream>
#include <boost/system/error_code.hpp>

using namespace boost::system;

void fail(error_code& ec) {
	ec = errc::make_error_code(errc::not_supported);
}

int main() {
	error_code ec;
	fail(ec);

	std::cout << ec.value() << std::endl;
	std::cout << ec.category().name() << std::endl;
}
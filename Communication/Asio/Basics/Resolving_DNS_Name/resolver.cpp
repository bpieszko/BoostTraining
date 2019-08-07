#include <boost/asio.hpp>
#include <iostream>

using namespace boost;

int main() {
	std::string host = "panoramafirm.pl";
	std::string port_num = "80";

	asio::io_service ios;
	asio::ip::tcp::resolver::query resolver_query(
		host, port_num,
		asio::ip::tcp::resolver::query::numeric_service
	);

	asio::ip::tcp::resolver resolver(ios);
	boost::system::error_code ec;

	asio::ip::tcp::resolver::iterator it =
		resolver.resolve(resolver_query, ec);

	if (ec.value() != 0) {
		std::cout << "Error: " << ec.value();
		return ec.value();
	}

	asio::ip::tcp::resolver::iterator it_end;

	for (; it != it_end; ++it) {
		asio::ip::tcp::endpoint ep = it->endpoint();
	}

	return 0;
}
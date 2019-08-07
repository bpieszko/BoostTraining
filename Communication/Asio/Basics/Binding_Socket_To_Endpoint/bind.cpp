#include <boost/asio.hpp>
#include <iostream>

using namespace boost;

int main() {
	unsigned short port_num = 3333;

	asio::ip::tcp::endpoint ep(
		asio::ip::address_v4::any(),
		port_num
	);
	asio::io_service ios;
	asio::ip::tcp::acceptor acceptor(
		ios,
		ep.protocol()
	);
	boost::system::error_code ec;

	acceptor.bind(ep, ec);

	if (ec.value() != 0) {
		std::cout << "Error: " << ec.value();
	}

	return ec.value();
}
#include <boost/asio.hpp>
#include <iostream>

using namespace boost;

int main() {
	asio::io_service ios;
	asio::ip::tcp protocol = asio::ip::tcp::v6();
	asio::ip::tcp::acceptor acceptor(ios);
	boost::system::error_code ec;

	acceptor.open(protocol, ec);

	return ec.value();
}
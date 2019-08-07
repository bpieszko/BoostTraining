#include <boost/asio.hpp>
#include <iostream>

using namespace boost;

int main() {
	asio::io_service ios;
	asio::ip::udp protocol = asio::ip::udp::v6();
	asio::ip::udp::socket sock(ios);
	boost::system::error_code ec;

	sock.open(protocol, ec);

	return ec.value();
}
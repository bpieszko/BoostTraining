#include <boost/asio.hpp>
#include <iostream>

using namespace boost;

int main() {
	std::string raw_ip_address = "127.0.0.1";
	unsigned short port_num = 3333;

	try {
		asio::ip::tcp::endpoint ep(
			asio::ip::address::from_string(raw_ip_address),
			port_num
		);
		asio::io_service ios;
		asio::ip::tcp::socket sock(ios, ep.protocol());
		sock.connect(ep);
	}
	catch (system::system_error& e) {
		std::cerr << "Error code: " << e.code() << ". Message: " << e.what() << std::endl;
		return e.code().value();
	}

	return 0;
}
#include <boost/asio.hpp>
#include <iostream>

using namespace boost;

int main() {
	std::string host = "panoramafirm.pl";
	std::string port = "80";

	asio::io_service ios;
	asio::ip::tcp::resolver::query resolver_query(
		host, port,
		asio::ip::tcp::resolver::query::numeric_service
	);
	asio::ip::tcp::resolver resolver(ios);

	try {
		asio::ip::tcp::resolver::iterator it =
			resolver.resolve(resolver_query);
		asio::ip::tcp::socket sock(ios);
		asio::connect(sock, it);
	}
	catch (system::system_error& e) {
		std::cout << "Error: " << e.code() << ". Message: " << e.what() << std::endl;
		return e.code().value();
	}
	
	return 0;
}
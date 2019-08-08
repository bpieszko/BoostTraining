#include <boost/asio.hpp>
#include <iostream>
#include <thread>

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

		std::shared_ptr<asio::ip::tcp::socket> sock(
			new asio::ip::tcp::socket(ios, ep.protocol())
		);

		sock->async_connect(
			ep,
			[sock](const boost::system::error_code& ec) {
				if (ec.value() != 0) {
					if (ec == asio::error::operation_aborted) {
						std::cerr << "operation cancelled" << std::endl;
					}
					else {
						std::cout << "error occurred" << std::endl;
					}
					return;
				}
			}
		);

		std::thread worker_thread([&ios]() {
			try {
				ios.run();
			}
			catch (system::system_error& e) {
				std::cerr << "error occured 2" << std::endl;
			}
		});

		std::this_thread::sleep_for(std::chrono::seconds(5));
		sock->cancel();
		worker_thread.join();
	}
	catch (system::system_error& e) {
		std::cerr << "error occured 3" << std::endl;
	}

	return 0;
}
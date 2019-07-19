#include <boost/thread.hpp>
#include <boost/thread/scoped_thread.hpp>
#include <boost/chrono.hpp>
#include <iostream>

void wait(const int seconds) {
	boost::this_thread::sleep_for(boost::chrono::seconds{seconds});
}

void thread() {
	for (int i = 0; i < 5; ++i) {
		std::cout << i << std::endl;
		wait(1);
	}
}

int main() {
	boost::scoped_thread<> t{boost::thread{thread}};
}

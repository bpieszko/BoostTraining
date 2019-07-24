#include <iostream>
#include <boost/thread.hpp>
#include <boost/chrono.hpp>

void wait(int seconds) {
	boost::this_thread::sleep_for(boost::chrono::seconds{seconds});
}

void thread() {
	for (int i = 0; i < 5; ++i) {
		wait(5);
		std::cout << i << std::endl;
	}
}

int main() {
	boost::thread t{thread};
	if (t.joinable())
		t.join();
}
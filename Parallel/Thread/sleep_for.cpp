#include <iostream>
#include <boost/thread.hpp>
#include <boost/chrono.hpp>

void wait(const int seconds) {
	boost::this_thread::sleep_for(boost::chrono::seconds{seconds});
}

void thread() {
	try {
		for (int i = 0; i < 5; ++i) {
			std::cout << i << std::endl;
			wait(1);
		}
	}
	catch (boost::thread_interrupted&) {}
}

int main() {
	boost::thread t{thread};
	wait(3);
	t.interrupt();
	t.join();
}
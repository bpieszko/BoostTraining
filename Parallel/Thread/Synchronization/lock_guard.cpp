#include <iostream>
#include <boost/thread.hpp>
#include <boost/chrono.hpp>

void wait(const int seconds) {
	boost::this_thread::sleep_for(boost::chrono::seconds{seconds});
} 

boost::mutex mutex;

void thread() {
	using boost::this_thread::get_id;

	for (int i = 0; i < 5; ++i) {
		wait(1);
		boost::lock_guard<boost::mutex> lock{mutex};
		std::cout << "Thread " << get_id() << ": " << i << std::endl;
	}
}

int main() {
	boost::thread t1{thread};
	boost::thread t2{thread};

	t1.join();
	t2.join();
}
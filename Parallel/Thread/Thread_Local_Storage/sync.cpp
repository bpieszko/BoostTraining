#include <iostream>
#include <boost/thread.hpp>

boost::mutex mutex;

void init() {
	static boost::thread_specific_ptr<bool> tls;

	if (!tls.get()) {
		tls.reset(new bool{true});
		boost::lock_guard<boost::mutex> lock{mutex};
		std::cout << "done" << std::endl;
	}
}

void thread() {
	init();
	init();
}

int main() {
	boost::thread_group tg;
	for (int i = 0; i < 3; ++i)
		tg.add_thread(new boost::thread{thread});
	tg.join_all();
}
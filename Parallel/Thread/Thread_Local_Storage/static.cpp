#include <iostream>
#include <algorithm>
#include <boost/thread.hpp>

boost::mutex mutex;

void init() {
	static bool done = false;
	
	boost::lock_guard<boost::mutex> lock{mutex};
	if (!done) {
		done = true;
		std::cout << "done" << std::endl;
	}
}

void thread() {
	init();
	init();
}

int main() {
	boost::thread_group tg;
	tg.add_thread(new boost::thread{thread});
	tg.add_thread(new boost::thread{thread});
	tg.add_thread(new boost::thread{thread});
	tg.join_all();
}
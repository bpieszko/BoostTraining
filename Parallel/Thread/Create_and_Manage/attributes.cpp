#include <boost/thread.hpp>
#include <boost/chrono.hpp>
#include <iostream>

void wait(const int seconds) {
	boost::this_thread::sleep_for(boost::chrono::seconds{seconds});
}

void thread() {
	int t[10000];
	for (int i = 0; i < 5; ++i)
		t[i] = i;
	try {
		for (int i = 0; i < 5; ++i ){
			std::cout << t[i] << std::endl;
			wait(1);
		}
	}
	catch (boost::thread_interrupted&) {}
}

int main() {
	boost::thread::attributes attrs;
	attrs.set_stack_size(1024);
	boost::thread t{attrs, thread};
	t.join();
}
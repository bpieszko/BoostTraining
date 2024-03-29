#define BOOST_THREAD_PROVIDES_FUTURE

#include <iostream>
#include <boost/thread.hpp>
#include <boost/thread/future.hpp>

int accumulate() {
	int sum = 0;
	for (int i = 0; i < 5; ++i) {
		sum += i;
	}
	return sum;
}

int main() {
	boost::future<int> f = boost::async(accumulate);
	std::cout << f.get() << std::endl;
}
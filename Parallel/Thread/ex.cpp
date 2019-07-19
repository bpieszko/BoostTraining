#include <iostream>
#include <cstdint>
#include <numeric>
#include <boost/timer/timer.hpp>
#include <boost/thread.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/thread/lock_guard.hpp>

void f(uint64_t& res, const uint64_t a, const uint64_t b) {
	for (uint64_t i = a; i < b; ++i) {
		res += i;
	}
}

int main() {
	const uint8_t HARDWARE_THREADS = boost::thread::hardware_concurrency();
	const uint64_t PART_LENGTH = 100'000'000 / HARDWARE_THREADS;

	std::vector<uint64_t> part(HARDWARE_THREADS, 0);

	boost::thread_group tg{};
	boost::thread* t[HARDWARE_THREADS];

	boost::timer::cpu_timer timer;

	for (int i = 0; i < HARDWARE_THREADS; ++i) {
		t[i] = new boost::thread(f, std::ref(part[i]), i * PART_LENGTH, (i + 1) * PART_LENGTH);
		tg.add_thread(t[i]);
	}
	
	tg.join_all();

	std::cout << timer.format() << std::endl;;
 	std::cout << std::accumulate(part.begin(), part.end(), 0) << std::endl;
}
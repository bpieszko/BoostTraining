#include <iostream>
#include <boost/heap/priority_queue.hpp>

using namespace boost::heap;

int main () {
	priority_queue<int> pq;
	pq.push(2);
	pq.push(3);
	pq.push(1);

	for (int i : pq) {
		std::cout << i << std::endl;
	}

	priority_queue<int> pq2;
	pq2.push(3);
	pq2.push(4);
	pq2.push(1);

	std::cout << std::boolalpha << (pq > pq2) << std::endl;
}
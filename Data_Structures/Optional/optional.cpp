#include <iostream>
#include <cstdlib>
#include <sys/time.h>
#include <cmath>
#include <boost/optional.hpp>

using namespace boost;

optional<int> get_even_random_number()
{
	int i = std::rand();
	return optional<int>{i % 2 == 0, i};
}

int main () {
	struct timeval time;
	gettimeofday(&time, 0);
	srand(time.tv_sec * 1000 + time.tv_usec % 1000);

	optional<int> i = get_even_random_number();

	if (i)
		std::cout << std::sqrt(static_cast<float>(*i)) << std::endl;

	if (i.is_initialized())
		std::cout << std::sqrt(static_cast<float>(i.get())) << std::endl;

	double d = get_optional_value_or(i, 0);

	std::cout << d << std::endl;

	return 0;
}
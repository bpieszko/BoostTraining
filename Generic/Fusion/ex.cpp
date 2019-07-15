#include <boost/math/constants/constants.hpp>
#include <boost/fusion/algorithm.hpp>
#include <boost/fusion/adapted.hpp>
#include <boost/fusion/sequence.hpp>
#include <boost/mpl/int.hpp>
#include <iostream>

using namespace boost::fusion;

struct animal
{
	std::string name;
	int legs;
	bool has_tail;
};

BOOST_FUSION_ADAPT_STRUCT(animal,
	(std::string, name)
	(int, legs)
	(bool, has_tail)
)

struct important_numbers
{
	const float pi = boost::math::constants::pi<float>();
	const double e = boost::math::constants::e<double>();
};

BOOST_FUSION_ADAPT_STRUCT(important_numbers,
	(const float, pi)
	(const double, e)
)


struct print {
	template <typename T>
	void operator()(const T& t) const {
		std::cout << t << std::endl;
	}
};

template <class T>
void debug(const T &t)
{
	for_each(t, print{});
}

int main()
{
	animal a{ "cat", 4, true };
	debug(a);

	important_numbers in;
	debug(in);
}
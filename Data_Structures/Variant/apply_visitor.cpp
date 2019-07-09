#include <iostream>
#include <string>
#include <boost/variant.hpp>

struct output : public boost::static_visitor<>
{
	void operator() (double d) const { std::cout << d << std::endl; }
	void operator() (char c) const { std::cout << c << std::endl; }
	void operator() (std::string s) const { std::cout << s << std::endl; }
};

struct better_output : public boost::static_visitor<>
{
	template <typename T>
	void operator() (T t) const { std::cout << t << std::endl; }
};

int main () {
	boost::variant<double, char, std::string> v;

	v = 3.14;
	boost::apply_visitor(output{}, v);

	v = 'd';
	boost::apply_visitor(output{}, v);

	v = "String";
	boost::apply_visitor(output{}, v);


	v = 3.14;
	boost::apply_visitor(better_output{}, v);

	v = 'd';
	boost::apply_visitor(better_output{}, v);

	v = "String";
	boost::apply_visitor(better_output{}, v);
}
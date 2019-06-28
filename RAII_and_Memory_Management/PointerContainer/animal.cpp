#include <iostream>
#include <boost/ptr_container/ptr_vector.hpp>

class Animal {
private:
	std::string name;
	unsigned short legs;
	bool has_tail;

public:
	Animal() = default;
	~Animal() = default;

	Animal(std::string name, unsigned short legs, bool has_tail) :
		name(name),
		legs(legs),
		has_tail(has_tail) { }

	bool operator < (const Animal & oth) const {
		if (legs != oth.legs) return legs < oth.legs;
		return false;
	}

	friend std::ostream& operator << (std::ostream& out, const Animal& a) {
		out << "[" << a.name << ", " << a.legs << ", " << std::boolalpha << a.has_tail << "]";
		return out;
	}

	friend std::istream& operator >> (std::istream& in, Animal& a) {
		in >> a.name >> a.legs >> a.has_tail;
		return in;
	}
};

int main () {
	int n; std::cin >> n;
	boost::ptr_vector<Animal> v;

	while (n--) {
		v.push_back(new Animal());
		std::cin >> v.back();
	}

	std::sort(v.begin(), v.end());

	for (auto & i : v) {
		std::cout << i << std::endl;
	}
	return 0;
}
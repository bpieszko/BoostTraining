#include <string>
#include <vector>
#include <iostream>
#include <boost/multi_index_container.hpp>
#include <boost/multi_index/member.hpp>
#include <boost/multi_index/hashed_index.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <boost/multi_index/identity.hpp>
#include <boost/multi_index/mem_fun.hpp>

using namespace boost::multi_index;

struct animal
{
	std::string name;
	int legs;
	bool has_tail;

	bool operator< (const animal& a) const {
		return legs < a.legs;
	}

	const animal* getAnimal() const {
		return this;
	}
};

typedef multi_index_container<
	animal,
	indexed_by<
		hashed_non_unique<
			member<
				animal, std::string, &animal::name
			>
		>,
		ordered_non_unique<
			member<
				animal, int, &animal::legs
			>
		>,
		ordered_non_unique<
			member<
				animal, bool, &animal::has_tail
			>
		>
	>
> animal_multi;


class animals_container
{
private:
	animal_multi animals;

public:
	void add(animal a)
	{
		animals.insert(a);
	}

	const animal *find_by_name(const std::string &name) const
	{
		return animals.get<0>().find(name)->getAnimal();
	}

	std::vector<animal> find_by_legs(int from, int to) const
	{
		auto it = animals.get<1>().lower_bound(from);
		auto end = animals.get<1>().upper_bound(to);

		std::vector<animal> res;

		for (; it != end; it++)
			res.push_back(*it);

		return res;
	}

	std::vector<animal> find_by_tail(bool has_tail) const
	{
		auto it = animals.get<2>().lower_bound(has_tail);
		auto end = animals.get<2>().upper_bound(has_tail);

		std::vector<animal> res;

		for (; it != end; it++)
			res.push_back(*it);

		return res;
	}
};

int main()
{
	animals_container animals;
	animals.add({ "cat", 4, true });
	animals.add({ "ant", 6, false });
	animals.add({ "spider", 8, false });
	animals.add({ "shark", 0, false });

	const animal *a = animals.find_by_name("cat");
	if (a)
		std::cout << a->name << " has " << a->legs << " legs\n";

	auto animals_with_6_to_8_legs = animals.find_by_legs(6, 9);
	for (auto a : animals_with_6_to_8_legs)
		std::cout << a.name << " has " << a.legs << " legs\n";

	auto animals_without_tail = animals.find_by_tail(false);
	for (auto a : animals_without_tail)
		std::cout << a.name << " has no tail\n";
}
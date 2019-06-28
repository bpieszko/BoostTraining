#include <iostream>
#include <boost/scope_exit.hpp>

int* foo() {
	int* i = new int{10};
	
	BOOST_SCOPE_EXIT(&i)
	{
		delete i;
		i = 0;
	} BOOST_SCOPE_EXIT_END

	std::cout << *i << std::endl;
	return i;
}

int main () {
	int *j = foo();
	std::cout << *j << std::endl;
}
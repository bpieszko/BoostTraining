#include <iostream>
#include <functional>
#include <boost/function.hpp>

struct world {
	void hello(std::ostream& os) {
		std::cout << "Hello world!" << std::endl;
	}
};

int main() {
	boost::function<void(world*, std::ostream&)> f = &world::hello;
	world w;
	f(&w, std::ref(std::cout));
}
#include <iostream>
#include <iterator>
#include <algorithm>
#include <utility>
#include <boost/graph/adjacency_list.hpp>

int main () {
	boost::adjacency_list<> g;

	boost::add_vertex(g);
	boost::add_vertex(g);
	boost::add_vertex(g);
	boost::add_vertex(g);

	std::pair<
		boost::adjacency_list<>::vertex_iterator,
		boost::adjacency_list<>::vertex_iterator
	> vs = boost::vertices(g);

	std::copy(
		vs.first, vs.second,
		std::ostream_iterator<boost::adjacency_list<>::vertex_descriptor>{std::cout, "\n"}
	);

	return 0;
}
#include <iostream>
#include <iterator>
#include <algorithm>
#include <tuple>
#include <boost/graph/adjacency_list.hpp>

int main () {
	typedef boost::adjacency_list<
		boost::setS,
		boost::vecS,
		boost::undirectedS
	> graph;

	graph g;

	enum { a, b, c, d };

	boost::add_edge(a, b, g);
	boost::add_edge(b, c, g);
	boost::add_edge(c, d, g);
	boost::add_edge(d, a, g);

	graph::edge_iterator it, end;
	std::tie(it, end) = boost::edges(g);

	std::copy(
		it, end, 
		std::ostream_iterator<graph::edge_descriptor>{std::cout, "\n"}
	);

	return 0;
}
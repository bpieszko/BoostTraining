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

	enum {a, b, c, d};

	boost::add_edge(a, b, g);
	boost::add_edge(b, c, g);
	boost::add_edge(c, d, g);
	boost::add_edge(d, a, g);

	graph::adjacency_iterator vit, vend;
	std::tie(vit, vend) = boost::adjacent_vertices(a, g);

	std::copy(
		vit, vend,
		std::ostream_iterator<graph::vertex_descriptor>{std::cout, "\n"}
	);

	graph::out_edge_iterator eit, eend;
	std::tie(eit, eend) = boost::out_edges(a, g); // in_edges
	std::for_each(
		eit, eend,
		[&g](graph::edge_descriptor it) {
			std::cout << boost::target(it, g) << std::endl;
		}
	);

	return 0;
}
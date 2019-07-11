#include <iostream>
#include <utility>
#include <array>
#include <boost/graph/adjacency_list.hpp>

int main () {
	std::array<std::pair<int, int>, 4> edges{{
		{0, 1},
		{1, 2},
		{2, 3},
		{3, 0}
	}};

	typedef boost::adjacency_list<
		boost::setS,
		boost::vecS,
		boost::undirectedS
	> graph;

	graph g{edges.begin(), edges.end(), 4};

	std::cout << boost::num_vertices(g) << " " << boost::num_edges(g) << std::endl;

	// clear()

	return 0;
}
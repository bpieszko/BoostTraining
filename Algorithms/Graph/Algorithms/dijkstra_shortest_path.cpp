#include <iostream>
#include <utility>
#include <boost/array.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>
#include <boost/graph/named_function_params.hpp>

int main () {
	boost::array<std::pair<int, int>, 4> edges{{
		{0, 1},
		{1, 2},
		{2, 3},
		{3, 0}
	}};

	typedef boost::adjacency_list<
		boost::listS,
		boost::vecS,
		boost::undirectedS,
		boost::no_property,
		boost::property<boost::edge_weight_t, int>
	> graph;

	std::array<int, 4> weights{{2, 1, 1, 1}};

	graph g{edges.begin(), edges.end(), weights.begin(), 4};

	boost::array<int, 4> directions;

	boost::dijkstra_shortest_paths(
		g, 2,
		boost::predecessor_map(directions.begin())
	);;

	int p = 0;
	while (p != 2) {
		std::cout << p << std::endl;
		p = directions[p];
	}
	std::cout << p << std::endl;

	return 0;
}
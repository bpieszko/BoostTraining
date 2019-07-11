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

	struct edge_properties {
		int weight;
	};

	typedef boost::adjacency_list<
		boost::listS,
		boost::vecS,
		boost::undirectedS,
		boost::no_property,
		edge_properties
	> graph;

	boost::array<edge_properties, 4> props{{2, 1, 1, 1}};
	graph g{edges.begin(), edges.end(), props.begin(), 4};

	boost::array<int, 4> directions;
	boost::dijkstra_shortest_paths(
		g, 2,
		boost::predecessor_map(
			directions.begin()
		).weight_map(
			boost::get(&edge_properties::weight, g)
		)
	);

	int p = 0;
	while (p != 2) {
		std::cout << p << std::endl;
		p = directions[p];
	}
	std::cout << p << std::endl;

	return 0;
}
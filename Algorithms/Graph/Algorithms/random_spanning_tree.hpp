#include <iostream>
#include <cstdint>
#include <random>
#include <ctime>
#include <utility>
#include <boost/array.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/random_spanning_tree.hpp>
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
		boost::undirectedS
	> graph;

	graph g{edges.begin(), edges.end(), 4};

	boost::array<int, 4> predecessors;

	std::mt19937 gen{static_cast<uint32_t>(std::time(0))};
	boost::random_spanning_tree(
		g, gen,
		boost::predecessor_map(
			predecessors.begin()
		).root_vertex(0)
	);

	int p = 0;
	while (p != -1) {
		std::cout << p << std::endl;
		p = predecessors[p];
	}

	return 0;
}
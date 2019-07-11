#include <iostream>
#include <algorithm>
#include <utility>
#include <array>
#include <boost/array.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/breadth_first_search.hpp>
#include <boost/graph/named_function_params.hpp>
#include <boost/graph/visitors.hpp>

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

	boost::array<int, 4> predecessors;
	predecessors[2] = 2;

	boost::breadth_first_search(
		g, 2,
		boost::visitor(
			boost::make_bfs_visitor(
				boost::record_predecessors(
					predecessors.begin(),
					boost::on_tree_edge{}
				)
			)
		)
	);

	int p = 0;
	while (p != 2)
	{
		std::cout << p << std::endl;
		p = predecessors[p];
	}

	std::cout << p << std::endl;

	return 0;
}
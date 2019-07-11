#include <iostream>
#include <algorithm>
#include <iterator>
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

	boost::array<int, 4> distances{{0}};

	boost::breadth_first_search(
		g, 0,
		boost::visitor(
			boost::make_bfs_visitor(
				boost::record_distances(
					distances.begin(),
					boost::on_tree_edge{}
				)
			)
		)
	);

	std::copy(
		distances.begin(),
		distances.end(),
		std::ostream_iterator<int>{std::cout, "\n"}	
	);

	return 0;
}
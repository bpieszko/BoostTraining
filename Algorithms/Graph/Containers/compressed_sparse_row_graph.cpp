#include <array>
#include <utility>
#include <boost/graph/compressed_sparse_row_graph.hpp>

int main () {
	std::array<std::pair<int, int>, 4> edges{{
		{0, 1},
		{1, 2},
		{2, 3},
		{3, 0}
	}};

	typedef boost::compressed_sparse_row_graph<
		boost::bidirectionalS
	> graph;

	graph g{boost::edges_are_unsorted_multi_pass, edges.begin(), edges.end(), 4};

	return 0;
}
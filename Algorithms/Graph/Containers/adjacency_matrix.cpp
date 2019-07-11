#include <boost/graph/adjacency_matrix.hpp>
#include <array>
#include <utility>

int main() {
	std::array<std::pair<int, int>, 4> edges{{
		{0, 1},
		{1, 2},
		{2, 3},
		{3, 0}
	}};

	typedef boost::adjacency_matrix<boost::undirectedS> graph;
	graph g{edges.begin(), edges.end(), 4};
	
	return 0;
}
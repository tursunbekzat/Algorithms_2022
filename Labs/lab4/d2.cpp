// C++ implementation of
// the above approach
#include <bits/stdc++.h>
using namespace std;

// Function to add edges to the tree
void add_edge(int a, int b,
			vector<vector<int> >& tree)
{
	// 0-based indexing
	a--, b--;

	tree[a].push_back(b);
	tree[b].push_back(a);
}

// Function to print sum of
// nodes on all levels of a tree
void dfs(int u, int level, int par,
		int node_values[], vector<vector<int> >& tree,
		map<int, int>& sum, int& depth)
{
	// update max depth of tree
	depth = max(depth, level);

	// Add value of current node
	// to its corresponding level
	sum[level] += node_values[u];

	for (int child : tree[u]) {

		if (child == par)
			continue;

		// Recursive traverse child nodes
		dfs(child, level + 1, u, node_values,
			tree, sum, depth);
	}
}

// Function to calculate sum of
// nodes of each level of the Tree
void getSum(int node_values[],
			vector<vector<int> >& tree)
{
	// Depth of the tree
	int depth = 0;

	// Stores sum at each level
	map<int, int> sum;

	dfs(0, 0,
		-1, node_values,
		tree, sum, depth);

	// Print final sum
	for (int i = 0; i <= depth; i++) {
		cout << "Sum of level " << i
			<< " = " << sum[i] << endl;
	}
}

// Driver Code
int32_t main()
{

	// Create a tree structure
	int N = 10;

	vector<vector<int> > tree(N);
	add_edge(1, 2, tree);
	add_edge(1, 3, tree);
	add_edge(2, 4, tree);
	add_edge(3, 5, tree);
	add_edge(3, 8, tree);
	add_edge(5, 6, tree);
	add_edge(5, 7, tree);
	add_edge(8, 9, tree);
	add_edge(8, 10, tree);

	int node_values[]
		= { 2, 3, 4, 4, 7,
			6, 2, 3, 9, 1 };

	// Function call to get the sum
	// of nodes of different level
	getSum(node_values, tree);

	return 0;
}

#include <iostream>
using namespace std;

// Adjacency Matrix
/* int main()
{
    // n is the number of vertices
    // m is the number of edges
    int n, m;
    cin >> n >> m;
    int adjMat[n + 1][n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adjMat[u][v] = 1;
        adjMat[v][u] = 1;
    }

    for (int i(0); i < m; i++)
    {
        for (int j(0); j < m; j++)
        {
            cout << adjMat[i][j] << ' ';
        }
        cout << "\n";
    }

    return 0;
}
*/


// Adjacency List
// A simple representation of graph using STL
// A utility function to add an edge in an
// undirected graph.
/*
void addEdge(vector<int> adj[], int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

// A utility function to print the adjacency list
// representation of graph
void printGraph(vector<int> adj[], int V)
{
	for (int v = 0; v < V; ++v) {
		cout << "\n Adjacency list of vertex " << v
			<< "\n head ";
		for (auto x : adj[v])
			cout << "-> " << x;
		printf("\n");
	}
}

// Driver code
int main()
{
	int V = 5;
	vector<int> adj[V];
	addEdge(adj, 0, 1);
	addEdge(adj, 0, 4);
	addEdge(adj, 1, 2);
	addEdge(adj, 1, 3);
	addEdge(adj, 1, 4);
	addEdge(adj, 2, 3);
	addEdge(adj, 3, 4);
	printGraph(adj, V);
	return 0;
}
*/



// representation of graphs using sets
/*
#include <bits/stdc++.h>
using namespace std;

struct Graph {
	int V;
	set<int>* adjList;
};

// A utility function that creates a graph of V vertices
Graph* createGraph(int V)
{
	Graph* graph = new Graph;
	graph->V = V;

	// Create an array of sets representing
	// adjacency lists. Size of the array will be V
	graph->adjList = new set<int >[V];

	return graph;
}

// Adds an edge to an undirected graph
void addEdge(Graph* graph, int src, int dest)
{
	// Add an edge from src to dest. A new
	// element is inserted to the adjacent
	// list of src.
	graph->adjList[src].insert(dest);

	// Since graph is undirected, add an edge
	// from dest to src also
	graph->adjList[dest].insert(src);
}

// A utility function to print the adjacency
// list representation of graph
void printGraph(Graph* graph)
{
	for (int i = 0; i < graph->V; ++i) {
		set<int> lst = graph->adjList[i];
		cout << endl << "Adjacency list of vertex "
			<< i << endl;

		for (auto itr = lst.begin(); itr != lst.end(); ++itr)
			cout << *itr << " ";
		cout << endl;
	}
}

// Searches for a given edge in the graph
void searchEdge(Graph* graph, int src, int dest)
{
	auto itr = graph->adjList[src].find(dest);
	if (itr == graph->adjList[src].end())
		cout << endl << "Edge from " << src
			<< " to " << dest << " not found."
			<< endl;
	else
		cout << endl << "Edge from " << src
			<< " to " << dest << " found."
			<< endl;
}

// Driver code
int main()
{
	// Create the graph given in the above figure
	int V = 5;
	struct Graph* graph = createGraph(V);
	addEdge(graph, 0, 1);
	addEdge(graph, 0, 4);
	addEdge(graph, 1, 2);
	addEdge(graph, 1, 3);
	addEdge(graph, 1, 4);
	addEdge(graph, 2, 3);
	addEdge(graph, 3, 4);

	// Print the adjacency list representation of
	// the above graph
	printGraph(graph);

	// Search the given edge in the graph
	searchEdge(graph, 2, 1);
	searchEdge(graph, 0, 3);

	return 0;
}
*/



// program to find transpose of a graph.
#include <bits/stdc++.h>
using namespace std;

// function to add an edge from vertex source to vertex dest
void addEdge(vector<int> adj[], int src, int dest)
{
	adj[src].push_back(dest);
}

// function to print adjacency list of a graph
void displayGraph(vector<int> adj[], int v)
{
	for (int i = 0; i < v; i++) {
		cout << i << "--> ";
		for (int j = 0; j < adj[i].size(); j++)
			cout << adj[i][j] << " ";
		cout << "\n";
	}
}

// function to get Transpose of a graph taking adjacency
// list of given graph and that of Transpose graph
void transposeGraph(vector<int> adj[],
					vector<int> transpose[], int v)
{
	// traverse the adjacency list of given graph and
	// for each edge (u, v) add an edge (v, u) in the
	// transpose graph's adjacency list
	for (int i = 0; i < v; i++)
		for (int j = 0; j < adj[i].size(); j++)
			addEdge(transpose, adj[i][j], i);
}

int main()
{
	int v = 5;
	vector<int> adj[v];
	addEdge(adj, 0, 1);
	addEdge(adj, 0, 4);
	addEdge(adj, 0, 3);
	addEdge(adj, 2, 0);
	addEdge(adj, 3, 2);
	addEdge(adj, 4, 1);
	addEdge(adj, 4, 3);

	// Finding transpose of graph represented
	// by adjacency list adj[]
	vector<int> transpose[v];
	transposeGraph(adj, transpose, v);

	// displaying adjacency list of transpose
	// graph i.e. b
	displayGraph(transpose, v);

	return 0;
}

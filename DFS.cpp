#include <iostream>
#include <vector>
#include <list>
#include <map>

using namespace std;

// Class to represent a directed graph using adjacency list
class Graph {
    // map to store the adjacency list: <Vertex, List of Neighbors>
    map<int, list<int>> adj;

    // Recursive helper function for DFS
    void DFSUtil(int v, map<int, bool>& visited) {
        // Mark the current node as visited and print it
        visited[v] = true;
        cout << v << " ";

        // Recur for all the vertices adjacent to this vertex
        for (int neighbor : adj[v]) {
            if (!visited[neighbor]) {
                DFSUtil(neighbor, visited);
            }
        }
    }

public:
    // Function to add an edge to the graph
    void addEdge(int v, int w) {
        adj[v].push_back(w); // Add w to v's list.
    }

    // DFS traversal from a given source vertex
    void DFS(int startNode) {
        // Map to keep track of visited vertices.
        // Default value is false for any newly accessed key.
        map<int, bool> visited;

        cout << "Depth First Traversal starting from vertex " << startNode << ":\n";
        DFSUtil(startNode, visited);
        cout << endl;
    }
};

int main() {
    Graph g;

    // Adding edges to the graph
    // 0 -> 1, 0 -> 2
    // 1 -> 2
    // 2 -> 0, 2 -> 3
    // 3 -> 3 (self loop)
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    g.DFS(2);

    return 0;
}

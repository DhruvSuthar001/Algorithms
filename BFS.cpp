#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <queue>

using namespace std;

// Class to represent a directed graph using adjacency list
class Graph {
    // map to store the adjacency list: <Vertex, List of Neighbors>
    map<int, list<int>> adj;

public:
    // Function to add an edge to the graph
    void addEdge(int v, int w) {
        adj[v].push_back(w); // Add w to v's list
    }

    // BFS traversal from a given source vertex
    void BFS(int startNode) {
        // Map to keep track of visited vertices
        map<int, bool> visited;

        // Create a queue for BFS
        queue<int> q;

        // Mark the current node as visited and enqueue it
        visited[startNode] = true;
        q.push(startNode);

        cout << "Breadth First Traversal starting from vertex " << startNode << ":\n";

        while (!q.empty()) {
            // Dequeue a vertex from queue and print it
            int curr = q.front();
            cout << curr << " ";
            q.pop();

            // Get all adjacent vertices of the dequeued vertex.
            // If an adjacent has not been visited, mark it visited and enqueue it.
            for (int neighbor : adj[curr]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
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

    g.BFS(2);

    return 0;
}

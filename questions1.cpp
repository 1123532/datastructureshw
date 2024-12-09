#include <iostream>
#include <vector>
using namespace std;

// Function to create an adjacency list
vector<vector<int>> createAdjacencyList(int V, vector<pair<int, int>> edges) {
    // Initialize an empty adjacency list with V nodes
    vector<vector<int>> adjacencyList(V);
    
    // Add edges to the adjacency list
    for (auto edge : edges) {
        int u = edge.first;
        int v = edge.second;
        adjacencyList[u].push_back(v);
        adjacencyList[v].push_back(u); // Since the graph is undirected
    }
    
    return adjacencyList;
}

// Main function for testing
int main() {
    int V = 5;
    vector<pair<int, int>> edges = {{0, 1}, {0, 4}, {4, 1}, {4, 3}, {1, 3}, {1, 2}, {3, 2}};
    
    vector<vector<int>> adjacencyList = createAdjacencyList(V, edges);
    
    // Print the adjacency list
    for (int i = 0; i < V; i++) {
        cout << i << ": ";
        for (int neighbor : adjacencyList[i]) {
            cout << neighbor << " ";
        }
        cout << endl;
    }
    
    return 0;
}

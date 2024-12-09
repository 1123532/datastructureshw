#include <iostream>
#include <vector>
using namespace std;

// Helper function to perform DFS recursively
void dfsHelper(int node, vector<vector<int>> &adj, vector<bool> &visited, vector<int> &dfsResult) {
    visited[node] = true;
    dfsResult.push_back(node);

    // Traverse all neighbors of the current node in the order of the adjacency list
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfsHelper(neighbor, adj, visited, dfsResult);
        }
    }
}

// Function to perform DFS traversal
vector<int> dfsTraversal(int V, vector<vector<int>> &adj) {
    vector<int> dfsResult;      // To store the DFS traversal order
    vector<bool> visited(V, false); // To keep track of visited nodes
    
    // Start DFS from vertex 0
    dfsHelper(0, adj, visited, dfsResult);
    
    return dfsResult;
}

// Main function for testing
int main() {
    // Input: Adjacency list
    vector<vector<int>> adj = {{1, 2}, {0, 2}, {0, 1, 3, 4}, {2}, {2}};
    int V = adj.size();
    
    // Perform DFS
    vector<int> result = dfsTraversal(V, adj);
    
    // Print DFS traversal order
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;
    
    return 0;
}

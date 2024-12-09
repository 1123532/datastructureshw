#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Function to perform BFS traversal
vector<int> bfsTraversal(int V, vector<vector<int>> &adj) {
    vector<int> bfsResult;      // To store the BFS traversal order
    vector<bool> visited(V, false); // To keep track of visited nodes
    
    queue<int> q; // Queue for BFS
    q.push(0);    // Start BFS from vertex 0
    visited[0] = true;
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        bfsResult.push_back(node);
        
        // Traverse neighbors of the current node in the order of adjacency list
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    
    return bfsResult;
}

// Main function for testing
int main() {
    // Input: Adjacency list
    vector<vector<int>> adj = {{2, 3, 1}, {0}, {0, 4}, {0}, {2}};
    int V = adj.size();
    
    // Perform BFS
    vector<int> result = bfsTraversal(V, adj);
    
    // Print BFS traversal order
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;
    
    return 0;
}

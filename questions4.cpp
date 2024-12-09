#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

// Function to calculate the weight of the MST using Prim's Algorithm
int findMST(int V, vector<vector<pair<int, int>>> &adj) {
    // Min-heap priority queue to store edges in the form (weight, node)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<bool> visited(V, false); // To keep track of visited nodes
    int mstWeight = 0;             // Store the sum of weights in the MST

    // Start Prim's algorithm from vertex 0
    pq.push({0, 0}); // (weight, node)

    while (!pq.empty()) {
        auto [weight, node] = pq.top();
        pq.pop();

        // Skip this node if it has already been included in the MST
        if (visited[node]) continue;

        visited[node] = true;      // Mark the node as visited
        mstWeight += weight;       // Add the edge's weight to the total MST weight

        // Add all adjacent edges of this node to the priority queue
        for (auto &edge : adj[node]) {
            int adjNode = edge.first;
            int adjWeight = edge.second;

            if (!visited[adjNode]) {
                pq.push({adjWeight, adjNode});
            }
        }
    }

    return mstWeight;
}

// Main function for testing
int main() {
    int V = 3, E = 3;
    
    // Adjacency list representation
    vector<vector<pair<int, int>>> adj(V);
    adj[0].push_back({1, 5});
    adj[1].push_back({0, 5});
    adj[1].push_back({2, 3});
    adj[2].push_back({1, 3});
    adj[0].push_back({2, 1});
    adj[2].push_back({0, 1});

    // Find MST weight
    int mstWeight = findMST(V, adj);
    cout << "Minimum Spanning Tree Weight: " << mstWeight << endl;

    return 0;
}

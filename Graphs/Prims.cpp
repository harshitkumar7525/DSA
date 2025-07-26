#include <bits/stdc++.h>
using namespace std;
int spanningTree(int V, vector<vector<int>> adj[])
{
    vector<bool> visited(V, false);
    // Min heap: (weight, node, parent)
    priority_queue<tiii, vector<tiii>, greater<tiii>> pq;
    pq.push(make_tuple(0, 0, -1)); // Starting with node 0
    int ans = 0;
    while (!pq.empty())
    {
        auto element = pq.top();
        int wt = get<0>(element);
        int node = get<1>(element);
        int parent = get<2>(element);
        pq.pop();
        if (visited[node]) // If the node is already visited, skip it. Thus this prevents us from taking unnecessary edges.
            continue;
        ans += wt; // Add the weight of the edge to the answer
        visited[node] = true; // Mark the node as visited
        for (auto &neighbor : adj[node]) // Iterate through all neighbors of the current node
        {
            int adjNode = neighbor[0]; // Get the adjacent node
            int edgeWeight = neighbor[1]; // Get the weight of the edge to the adjacent node
            if (!visited[adjNode]) // If the adjacent node is not visited, push it to the priority queue
            {
                pq.push(make_tuple(edgeWeight, adjNode, node));
            }
        }
    }

    return ans;
}
int main()
{
    int V = 5; // Number of vertices
    vector<vector<int>> adj[V];
    adj[0] = {{1, 2}, {2, 3}};
    adj[1] = {{0, 2}, {2, 1}, {3, 4}};
    adj[2] = {{0, 3}, {1, 1}, {3, 5}};
    adj[3] = {{1, 4}, {2, 5}};
    adj[4] = {{1, 2}};

    int result = spanningTree(V, adj);
    cout << "Weight of the Minimum Spanning Tree: " << result << endl;
    return 0;
}
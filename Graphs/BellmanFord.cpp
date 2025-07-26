#include <bits/stdc++.h>
using namespace std;
vector<int> bellmanFord(int V, vector<vector<int>> &edges, int src)
{
    vector<int> dist(V, 1e8); // Initialize distances to infinity
    dist[src] = 0; // Distance from source to itself is 0
    // O(V*E)
    for (int i = 0; i < V - 1; i++) // V-1 iterations
    {   // Why V-1 ?
        /*
        Since the graph has V nodes
        In the worst case,
        we will need N-1 edges to reach from
        first to last node.
        Thereby, we iterate for V-1 iterations
        */
        for (auto &e : edges)
        {
            int u = e[0];
            int v = e[1];
            int wt = e[2];
            if (dist[u] == 1e8) // agr hm u node abhi tk nahi pahunche toh iss iteration ko skip kr do
                continue;
            int newCost = dist[u] + wt; // Calculate new cost to reach v from u
            if (newCost < dist[v]) // If the new cost is less than the current known cost
            {
                dist[v] = newCost; // Update the distance to v
            }
        }
    }
    for (auto &e : edges) // Check for negative weight cycles
    {
        /*
        Thought Process:
        If we can still relax an edge after V-1 iterations,
        it means there is a negative weight cycle in the graph.
        */
        int u = e[0];
        int v = e[1];
        int wt = e[2];
        if (dist[u] == 1e8)
            continue;
        int newCost = dist[u] + wt;
        if (newCost < dist[v]) // If we can still relax the edge
        {
            return {-1}; // Indicating a negative weight cycle
        }
    }
    return dist; // Return the shortest distances
}
int main()
{
    int V = 5; // Number of vertices
    vector<vector<int>> edges = {
        {0, 1, -1},
        {0, 2, 4},
        {1, 2, 3},
        {1, 3, 2},
        {1, 4, 2},
        {3, 2, 5},
        {3, 1, 1},
        {4, 3, -3}};
    int src = 0; // Starting vertex
    vector<int> result = bellmanFord(V, edges, src);

    if (result[0] == -1)
    {
        cout << "Negative weight cycle detected." << endl;
    }
    else
    {
        cout << "Shortest distances from source: ";
        for (int d : result)
        {
            cout << d << " ";
        }
        cout << endl;
    }
    return 0;
}
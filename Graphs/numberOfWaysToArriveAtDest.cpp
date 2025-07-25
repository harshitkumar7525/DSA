#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typdef pair<ll, int> pli;
/*
The number of ways to  arrive at a node is the sum of the number of ways to
arrive at all its preceding nodes of the same cost.
If we find a cheaper way to reach a node, we update the number of ways
to reach that node to the number of ways to reach the preceding node.
*/
int countPaths(int n, vector<vector<int>> &roads)
{
    vector<ll> dist(n, LLONG_MAX); // Distance array to store the minimum cost to reach each node
    vector<ll> ways(n, 0); // Ways array to store the number of ways to reach each node
    long long mod = 1e9 + 7; // Modulo value to prevent overflow
    vector<vector<pair<int, int>>> adj(n); // Adjacency list to represent the graph
    for (auto &e : roads)
    {
        adj[e[0]].push_back(make_pair(e[1], e[2]));
        adj[e[1]].push_back(make_pair(e[0], e[2]));
    }
    priority_queue<pli, vector<pli>, greater<pli>> pq; // Min-heap priority queue to process nodes based on minimum cost
    pq.push(make_pair(0, 0)); // Start from node 0 with cost 0
    dist[0] = 0; // Cost to reach the starting node is 0
    ways[0] = 1; // There is one way to reach the starting node
    // Dijkstra's algorithm to find the minimum cost and number of ways to reach each node
    while (!pq.empty())
    {
        pli path = pq.top();
        pq.pop();
        ll currCost = path.first;
        int node = path.second;
        for (auto &neigh : adj[node])
        {
            ll newCost = currCost + neigh.second;
            int newNode = neigh.first;
            if (newCost < dist[newNode]) 
            {
                // If we found a cheaper way to reach newNode
                dist[newNode] = newCost; // Update the minimum cost to reach newNode
                pq.push(make_pair(newCost, newNode)); // Add newNode to the priority queue
                ways[newNode] = ways[node] % mod; // Update the number of ways to reach newNode
            }
            else if (newCost == dist[newNode]) // If we found another way to reach newNode with the same cost
            {
                // Increment the number of ways to reach newNode
                ways[newNode] += (ways[node] % mod);
            }
        }
    }
    return ways[n - 1] % mod; // Return the number of ways to reach the last node (n-1) modulo mod
}
int main()
{
    int n = 7; // Number of nodes
    vector<vector<int>> roads = {
        {0, 1, 2}, {0, 3, 6}, {1, 2, 3}, {1, 3, 8}, {1, 4, 5},
        {2, 4, 7}, {3, 4, 9}, {3, 5, 1}, {4, 5, 2}, {4, 6, 3},
        {5, 6, 1}
    }; // Roads represented as {from, to, cost}

    int result = countPaths(n, roads);
    cout << "Number of ways to reach node " << n - 1 << ": " << result << endl;

    return 0;
}
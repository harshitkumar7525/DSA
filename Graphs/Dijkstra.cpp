#include<bits/stdc++.h>
using namespace std;
/*
Exaplaination:
O(E log V) time complexity is used for Dijkstra's algorithm using priority queue.
E is the number of edges and V is the number of vertices in the graph.
In worst case, every edge is processed once, and each insertion and
extraction from the priority queue takes O(log V) time. 
Since at worst the heap may have all vertices, the time complexity becomes O(E log V).
*/

vector<int> dijkstraUsingPQ(int V, vector<vector<int>> &edges, int src) // O((V+E)log V) time complexity
{
    vector<int> dist(V, INT_MAX); // Initialize distances to all vertices as infinite
    dist[src] = 0; // Distance from source to itself is 0
    vector<vector<pair<int, int>>> adj(V); // Adjacency list representation of the graph
    // Build the adjacency list
    for (auto &e : edges)
    {
        adj[e[0]].push_back(make_pair(e[1], e[2]));
        adj[e[1]].push_back(make_pair(e[0], e[2]));
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Min-heap priority queue to store (cost, node) pairs
    // Start with the source node
    pq.push(make_pair(0, src));
    while (!pq.empty()) // While there are nodes to process
    {
        int nodeCost = pq.top().first; // Cost to reach the current node
        int node = pq.top().second; // Current node
        pq.pop(); // Remove the current node from the queue
        for (auto &n : adj[node]) // Iterate through all neighbours of the current node
        {
            int newCost = nodeCost + n.second; // Calculate the new cost to reach the neighbour
            if (newCost < dist[n.first]) // If the new cost is less than the previously recorded cost
            {
                dist[n.first] = newCost; // Update the distance to the neighbour
                pq.push(make_pair(newCost, n.first)); // Push the neighbour into the priority queue with the new cost
            }
        }
    }
    return dist; // Return the distances from the source to all vertices
}
vector<int> dijkstra(int V, vector<vector<int>> &edges, int src)
{
    vector<int> dist(V, INT_MAX); // Initialize distances to all vertices as infinite
    dist[src] = 0; // Distance from source to itself is 0
    vector<vector<pair<int, int>>> adj(V); // Adjacency list representation of the graph
    for (auto &e : edges) // Build the adjacency list
    {
        adj[e[0]].push_back(make_pair(e[1], e[2]));
        adj[e[1]].push_back(make_pair(e[0], e[2]));
    }
    /*
    Set stores the data in ascending order
    */
    set<pair<int, int>> st; // Set to store (cost, node) pairs
    st.insert(make_pair(0, src)); // Start with the source node
    while (!st.empty()) // While there are nodes to process
    {
        auto vertex = *(st.begin()); // Get the node with the smallest cost
        st.erase(vertex);
        int nodeCost = vertex.first;
        int node = vertex.second;
        for (auto &n : adj[node])
        {
            int newCost = nodeCost + n.second;
            if (newCost < dist[n.first])
            {
                for(auto& p:st){ // this loop is used to remove the old(higher) cost of the node from the set
                    if(p.second==n.first){
                        st.erase(p);
                    }
                }
                dist[n.first] = newCost;
                st.insert(make_pair(newCost, n.first));
            }
        }
    }
    return dist;
}
int main() {
    int V = 5; // Number of vertices
    vector<vector<int>> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 2},
        {2, 3, 1},
        {3, 4, 4}
    };
    int src = 0; 
    vector<int> distances = dijkstraUsingPQ(V, edges, src);

    for (int i = 0; i < V; i++) {
        cout << "Distance from source " << src << " to node " << i << " is " << distances[i] << endl;
    }
    
    return 0;
}
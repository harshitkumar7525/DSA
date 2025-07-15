#include <bits/stdc++.h>
using namespace std;
bool isCycle(int V, vector<vector<int>> &edges){
    vector<vector<int>> adj(V); // Adjacency list representation of the graph
    vector<bool> visited(V); // To keep track of visited nodes
    for (int i = 0; i < edges.size(); i++){ // creating the adjacency list
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    queue<pair<int, int>> q; // Queue for BFS
    for (int i = 0; i < V; i++){ // Iterate through all vertices because the graph may be disconnected
        if (!visited[i]){ // If the vertex is not visited, start BFS from it
            q.push({i, -1}); // Push the vertex and its parent (-1 for root)
            visited[i] = true; // Mark it as visited
            while (!q.empty()){ // Process the queue
                auto p = q.front();
                int curr = p.first;
                int parent = p.second;
                q.pop();
                for (auto &n : adj[curr]){
                    if (!visited[n]){
                        q.push({n, curr});
                        visited[n] = true;
                    }
                    else if (n != parent){ // If the adjacent node is visited and is not the parent, a cycle is detected
                        return true;
                    }
                }
            }
        }
    }
    return false;
}
int main(){
    vector<vector<int>> edges = {
        {0, 1}, {1, 2}, {2, 0}, // Cycle exists
        {3, 4}, {4, 5} // No cycle in this part
    };
    int V = 6; // Number of vertices
    cout << "Does the undirected graph contain a cycle? ";
    cout << (isCycle(V, edges) ? "Yes" : "No") << endl;
    return 0;
}
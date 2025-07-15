#include <bits/stdc++.h>
using namespace std;
bool isCycleUsingBFS(int V, vector<vector<int>> &edges){
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
bool dfs(int node,int parent,vector<vector<int>>& adj, vector<bool> &visited){
    visited[node]=true; // mark the current node as visited
    for(auto& n:adj[node]){ // iterate through its neighbours
        if(!visited[n]){ // if any neighbour is not visited traverse it
            if(dfs(n,node,adj,visited)) return true; // if any neighbour has cycle return true;
        } else if (parent != n){ // neighbour is already visited and it is not the parent 
            return true; // loop detected
        }
    }
    return false; //if loop not detected till now, which means graph doesn't have a loop
}
bool isCycleUsingDFS(int V, vector<vector<int>> &edges){
    vector<vector<int>> adj(V); // Adjacency list representation of the graph
    vector<bool> visited(V); // To keep track of visited nodes
    for (int i = 0; i < edges.size(); i++){ // creating the adjacency list
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool ans=true;
    for (int i = 0; i < V; i++){ // Iterate through all vertices because the graph may be disconnected
        if (!visited[i]){ // If the vertex is not visited, start DFS from it
           ans = dfs(i,-1,adj,visited);
           if(ans) return true;
        }
    }
    return ans;
}
int main(){
    vector<vector<int>> edges = {
        {0, 1}, {1, 2}, {2, 0}, // Cycle exists
        {3, 4}, {4, 5} // No cycle in this part
    };
    int V = 6; // Number of vertices
    cout << "Does the undirected graph contain a cycle? ";
    cout << (isCycleUsingDFS(V, edges) ? "Yes" : "No") << endl;
    return 0;
}
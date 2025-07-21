#include <bits/stdc++.h>
using namespace std;
vector<bool> visited; // to keep track of visited nodes
vector<bool> inPath; // to keep track of nodes in the current path
bool dfsCheck(int node, vector<vector<int>> &adj) {
    visited[node] = true; // mark the node as visited
    inPath[node] = true; // mark the node as part of the current path
    for (auto &neighbour : adj[node]) { // iterate through all the neighbours of the node
        if (!visited[neighbour]) { // if the neighbour is not visited
            if (dfsCheck(neighbour, adj)) { // recursively call dfsCheck on the neighbour
                return true; // if a cycle is detected in the neighbour's path
            }
        }
        else if (inPath[neighbour]) { // if the neighbour is visited and is part of the current path
            return true; // cycle detected
        }
    }
    inPath[node] = false; // backtrack, remove the node from the current path
    return false; // no cycle detected in this path
}
bool isCyclicUsingDFS(int V, vector<vector<int>> &edges) {
    visited.resize(V, false); // initialize the visited vector
    inPath.resize(V, false); // initialize the inPath vector
    vector<vector<int>> adj(V); // adjacency list representation of the graph
    for (auto &e : edges) { // build the adjacency list
        adj[e[0]].push_back(e[1]);
    }
    for (int i = 0; i < V; i++) { // iterate through all the vertices
        if (!visited[i]) { // if the vertex is not visited
            if (dfsCheck(i, adj)) { // call dfsCheck on the vertex
                return true; // if a cycle is detected, return true
            }
        }
    }
    return false; // no cycle detected
}
bool isCyclicUsingBFS(int V, vector<vector<int>> &edges) {
        vector<int> topo; // to store the topological order
        vector<vector<int>> adj(V); // adjacency list representation of the graph
        vector<int> idg(V,0); // to store in-degrees of all nodes
        queue<int> q; // queue to store nodes with in-degree 0
        for(auto& e:edges){ // build the adjacency list and calculate in-degrees
            idg[e[1]]++;
            adj[e[0]].push_back(e[1]);
        }
        for(int i=0;i<V;i++){ // iterate through all the vertices
            if(idg[i]==0){ // if the in-degree is 0, push it to the queue
                q.push(i);
            }
        }
        while(!q.empty()){ // process nodes in the queue
            int curr = q.front(); // get the front node
            q.pop(); // remove it from the queue
            topo.push_back(curr); // add it to the topological order
            for(auto& n:adj[curr]){ // iterate through all the neighbours of the current node
                if(--idg[n]==0){ // remove the edge and check if the in-degree becomes 0
                    q.push(n); // if it does, push it to the queue
                }
            }
        }
        return topo.size()!=V; // if the topological order size is not equal to the number of vertices, a cycle exists
    }
int main()
{
    int V = 4;
    vector<vector<int>> edges = {
        {0.1},
        {0, 2},
        {1, 2},
        {2, 0},
        {2, 3}};
    cout << isCyclicUsingDFS(V, edges) << endl; // Output: 1 (true)
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
stack<int> topo;
vector<bool> visited;
void dfs(int node, vector<vector<int>> &adj)
{
    visited[node] = true; // mark the node as visited
    for (auto &neighbour : adj[node]) // iterate through all the neighbours of the node
    {
        if (!visited[neighbour]) // if the neighbour is not visited
        {
            dfs(neighbour, adj); // recursively call dfs on the neighbour
        }
    }
    topo.push(node); // after visiting all the neighbours, push the node onto the stack
}
// without kahn's algorithm using dfs
// time complexity O(V + E) where V is the number of vertices and E is the number of edges
vector<int> topologicalSortUsingDFS(int V, vector<vector<int>> &edges)
{
    visited.resize(V, false); // initialize the visited vector
    vector<vector<int>> adj(V); // adjacency list representation of the graph
    for (auto &e : edges) // build the adjacency list
    {
        adj[e[0]].push_back(e[1]);
    }
    for (int i = 0; i < V; i++) // iterate through all the vertices
    {
        if (!visited[i]) // if the vertex is not visited
        {
            dfs(i, adj); // call dfs on the vertex
        }
    }
    // after all the dfs calls, the stack will contain the nodes in topological order
    // we need to pop the elements from the stack to get the topological order
    vector<int> result;
    while (!topo.empty())
    {
        result.push_back(topo.top());
        topo.pop();
    }
    return result;
}
// Kahn's algorithm for topological sorting (BFS approach)
vector<int> topologicalSortUsingBFS(int V, vector<vector<int>> &edges)
{
    queue<int> q; // queue to store nodes with in-degree 0
    vector<int> inDegree(V, 0); // vector to store in-degrees of all nodes
    vector<vector<int>> adj(V); // adjacency list representation of the graph
    for (auto &e : edges) // build the adjacency list and calculate in-degrees
    {
        adj[e[0]].push_back(e[1]); // add edge from e[0] to e[1]
        inDegree[e[1]]++; // increment in-degree of e[1]
    }
    for (int i = 0; i < V; i++) // iterate through all the vertices
    {
        if (!inDegree[i]) // if the in-degree is 0
            q.push(i); // push it to the queue
    }
    vector<int> ans; // vector to store the topological order
    while (!q.empty()) // while the queue is not empty
    {
        int curr = q.front(); // get the front element of the queue
        q.pop(); // pop the front element from the queue
        ans.push_back(curr); // add the current node to the topological order
        for (auto &n : adj[curr]) // iterate through all the neighbours of the current node
        {
            inDegree[n]--; // decrement the in-degree of the neighbour
            if (inDegree[n] == 0) // if the in-degree becomes 0
            {
                q.push(n); // push the neighbour to the queue
            }
        }
    }
    return ans;
}
int main()
{
    int V = 6;
    vector<vector<int>> edges = {
        {1, 3},
        {2, 3},
        {4, 1},
        {4, 0},
        {5, 0},
        {5, 2}};
    vector<int> result = topologicalSortUsingBFS(V, edges);
    for (int i : result)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
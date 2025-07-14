#include<bits/stdc++.h>
using namespace std;
vector<int> bfs(vector<vector<int>>& adj) {
    unordered_set<int> visited;
    vector<int> bfsOrder;
    queue<int> q;
    int startNode = 0; // Starting from node 0, can be changed as needed
    q.push(startNode); // push the start
    visited.insert(startNode); // mark it as visited
    // The total time complexity of BFS is O(V + E) where V is the number of vertices and E is the number of edges.
    while(!q.empty()) {
        /*
        Each node is processed once, so the while loop runs O(V) times where V is the number of vertices.
        */
        int node = q.front(); // get the front node
        q.pop(); // remove it from the queue
        bfsOrder.push_back(node); // add it to the BFS order

        /*
        This for loop iterates k times, where k is the degree of the current node.
        O(sum of all degrees) = O(E) where E is the number of edges.
        */
        for(int neighbor : adj[node]) { // iterate through all neighbors
            if(visited.find(neighbor) == visited.end()) { // if neighbor is not visited
                visited.insert(neighbor); // mark it as visited
                q.push(neighbor); // push it to the queue
            }
        }
    }
    return bfsOrder;
}

int main(){
    vector<vector<int>> adj = {
        {1,2},
        {0,2},
        {0,1,3,4},
        {2},
        {2}
    };
    vector<int> bfsResult = bfs(adj);
    cout << "BFS Traversal Order: ";
    for(int node : bfsResult) {
        cout << node << " ";
    }
    cout << endl;
    return 0;
}
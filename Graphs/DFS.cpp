#include<bits/stdc++.h>
using namespace std;
void helper(vector<int> &dfs, unordered_set<int> &visited, int node,vector<vector<int>>& adj){
    dfs.push_back(node); // Add the current node to the DFS order
    for(auto &neighbour:adj[node]){ // Iterate through all neighbors of the current node
        if(visited.find(neighbour)==visited.end()){ // If the neighbor has not been visited
            visited.insert(neighbour); // Mark the neighbor as visited
            helper(dfs,visited,neighbour,adj); // Recursively call the helper function for the neighbor
        }
    }
    // Once all the neighbors are processed, the function returns to the previous node in the recursion stack
}
vector<int> dfs(vector<vector<int>>& adj,int startNode) {
    vector<int> dfs; // To store the DFS traversal order
    unordered_set<int> visited; // To keep track of visited nodes
    visited.insert(startNode); // Mark the starting node as visited
    helper(dfs,visited,startNode,adj); // Call the helper function to perform DFS from the starting node
    return dfs; 
}
int main(){
    vector<vector<int>> adj = {
        {1,2},
        {0,2},
        {0,1,3,4},
        {2},
        {2}
    };
    vector<int> dfsResult = dfs(adj);
    cout << "DFS Traversal Order: ";
    for(int node : dfsResult) {
        cout << node << " ";
    }
    cout << endl;
    return 0;
}
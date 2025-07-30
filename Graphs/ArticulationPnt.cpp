#include<bits/stdc++.h>
using namespace std;
class Solution {
    private:
    vector<int> tin; // vector to store discovery times of nodes
    vector<int> low; // vector to store the lowest discovery time reachable from a node
    vector<bool> visited; // vector to track visited nodes
    vector<vector<int>> adj; // adjacency list representation of the graph
    unordered_set<int> points; // set to store articulation points
    int timer = 1; // timer to assign discovery times
    void dfs(int u,int parent){
        visited[u]=true; // mark the current node as visited
        low[u]=tin[u]=timer++; // set discovery time and low value to current timer
        int child=0; // to count the number of children of the current node
         // iterate through all adjacent nodes
        for(auto& v:adj[u]){
            if(v==parent) continue; // skip the parent node to avoid going back
            if(!visited[v]){ // if the adjacent node is not visited
                child++; // increment the child count
                dfs(v,u); // recursively call dfs on the adjacent node
                low[u]=min(low[u],low[v]); // update the low value of the current node
                // '<' condition arises from the bridge condition
                // '=' condition arises when the point is the root node of a cycle
                if(tin[u]<=low[v] && parent!=-1){
                    points.insert(u);
                }
            } else { // if the adjacent node is already visited
                low[u]=min(tin[v],low[u]); // update the low value of the current node
            }
        }
        if(child>1 && parent==-1){ // if the current node is the root and has more than one child
            // then it is an articulation point
            points.insert(u);
        }
    }
  public:
    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        tin.resize(V);
        low.resize(V);
        visited.resize(V,false);
        adj.resize(V);
        for(auto& e:edges){
            int u=e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                dfs(i, -1);
            }
        }
        if(points.empty()) return {-1};
        else{
            return vector<int>(points.begin(),points.end());
        } 
    }
};
int main() {
    Solution sol;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 0}, {1, 3}};
    int V = 4;
    vector<int> result = sol.articulationPoints(V, edges);
    
    for(int point : result) {
        cout << point << " ";
    }
    return 0;
}
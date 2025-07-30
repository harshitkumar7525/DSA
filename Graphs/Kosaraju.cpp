#include<bits/stdc++.h>
using namespace std;
/*
Why do we reverse the graph?
agar hm graph ko ulta karte hain tabhi scc ko kuch fark nhi padta
kyuki agar ek node dusre se reach ho rha hai to dusra bhi pehle wale se reach ho rha hoga
So, reversing the graph does not change the strongly connected components.
But this prevents us from visited unwanted nodes which are not part of the current strongly connected component.
So, we reverse the graph to ensure that we only explore nodes that are part of the current strongly connected component.
*/
class Solution {
  private:
  stack<int> st; // stack to store the finishing order of nodes
  vector<bool> visited; // vector to track visited nodes
  void dfs(int u,vector<vector<int>> &adj){
      visited[u]=true; // mark the current node as visited
      for(auto& v:adj[u]){ // iterate through all adjacent nodes
          if(!visited[v]){ // if the adjacent node is not visited
              dfs(v,adj); // recursively call dfs on the adjacent node
          }
      }
      st.push(u); // push the current node onto the stack after all its adjacent nodes are processed
  }
  public:
    int kosaraju(vector<vector<int>> &adj) {
        int V = adj.size(); // number of vertices in the graph
        visited.resize(V,false); // initialize visited vector
        for(int i=0;i<V;i++){
            if(!visited[i]) dfs(i,adj); // perform DFS on unvisited nodes
        }
        vector<vector<int>> revAdj(V); // create a reversed adjacency list
        fill(visited.begin(), visited.end(), false); // reset visited vector for the second DFS
        for(int i=0;i<V;i++){ // reverse the edges
            for(auto& n:adj[i]){
                revAdj[n].push_back(i);
            }
        }
        int ans = 0; // number of times a new DFS is initiated = number of strongly connected components
        while(!st.empty()){ // while there are nodes in the stack
            if(!visited[st.top()]){ // if the top node is not visited
                dfs(st.top(),revAdj); // perform DFS on the reversed graph
                ans++; // increment the count of strongly connected components
            }
            st.pop(); // pop the top node from the stack
        }
        return ans; // return the number of strongly connected components
    }
};
int main() {
    Solution sol;
    // Example usage
    vector<vector<int>> graph = {
        {1, 2},
        {2, 0},
        {3, 4},
        {4, 5},
        {5, 3}
    };
    int result = sol.kosaraju(graph);
    cout << "Number of strongly connected components: " << result << endl;
    return 0;
}
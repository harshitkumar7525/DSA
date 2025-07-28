#include <bits/stdc++.h>
using namespace std;
class DisjointSet {
    private:
    vector<int> parent,size;
    public:
    DisjointSet(int V){
        parent.resize(V+1);
        size.resize(V+1,1);
        for(int i=1;i<=V;i++){
            parent[i]=i;
        }
    }
    int findParent(int u){
        if(u==parent[u]){
            return u;
        }
        return parent[u] = findParent(parent[u]);
    }
    void UnionBySize(int u, int v){
        int pu = findParent(u);
        int pv = findParent(v);
        if(pv==pu){
            return ;
        } else if (size[pu]<size[pv]){
            parent[pu]=pv;
            size[pv]+=size[pu];
        } else{
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};
class Solution {
  private:
    static bool comp(vector<int>& a, vector<int>& b){
        return a[2]<b[2];
    }
  public:
    int kruskalsMST(int V, vector<vector<int>> &edges) { // O(E log E)
        sort(edges.begin(),edges.end(),comp); // O(E log E)
        DisjointSet ds(V);
        int ans=0;
        for(auto& currEdge:edges){ // O(E)
            // currEdge[0] = u, currEdge[1] = v, currEdge[2] = weight
            if(ds.findParent(currEdge[0])!=ds.findParent(currEdge[1])){  // O(1)
                ans+=currEdge[2]; // add weight to answer
                ds.UnionBySize(currEdge[0],currEdge[1]); // O(1) amortized time complexity
            }
        }
        return ans;
    }
};
int main() {
    int V = 4;
    vector<vector<int>> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };
    Solution obj;
    cout << obj.kruskalsMST(V, edges) << endl;
    return 0;
}
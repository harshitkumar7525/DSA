#include<bits/stdc++.h>
using namespace std;
class DisjointSet {
 public:
    vector<int> parent, size;

    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);

        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int findUpar(int node) {
        if (parent[node] == node)
            return node;
        return parent[node] = findUpar(parent[node]); // path compression
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);

        if (ulp_u == ulp_v)
            return;
        if (size[ulp_v] < size[ulp_u]) {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        } else {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
    }
};

class Solution {
    private:
    vector<int> delRow = {-1, 0, 1, 0};
    vector<int> delCol = {0, 1, 0, -1};
    int n;
    int getCell(int r, int c) {
        return r * n + c; // convert 2D coordinates to 1D index
    }
    public:
    int swimInWater(vector<vector<int>>& grid) {
        n = grid.size();
        int targetCell = getCell(n - 1, n - 1); // target cell is the bottom-right corner

        // Apply kruskal
        // 1. sort edges on elevation
        // 2. Union on sorted
        // 3. Return the cellElevation if {{0 0 } {n-1 ,n-1 is connected

        DisjointSet ds(n * n);
        vector<bool> vis(n * n, false); // 1D vis[]
        vector<pair<int, pair<int, int>>> flat; // elevation, {row, col}

        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                flat.push_back({grid[r][c], {r, c}});
            }
        }
        sort(flat.begin(), flat.end()); // sorting based on elevation (increasing order)


        for (auto it : flat) { // take the smallest elevation cell first
            int ele = it.first;  // elevation of the current cell
            // coordinates of the current cell
            int r = it.second.first; 
            int c = it.second.second;

            int cell = getCell(r, c); // convert 2D coordinates to 1D index
            vis[cell] = true; // mark the current cell as visited


            for (int i = 0; i < 4; i++) { // check all 4 directions
                // calculate the new row and column indices
                int nrow = r + delRow[i];
                int ncol = c + delCol[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < n) { // check if the new cell is within bounds
                    int ncell = getCell(nrow, ncol); // convert 2D coordinates to 1D index
                    if(vis[ncell]) ds.unionBySize(cell, ncell); // if the new cell is visited, union the current cell with the new cell
                }
            }
            // agar union ke baad 0,0 aur targetCell connected hain to return current elevation
            if (ds.findUpar(0) == ds.findUpar(targetCell)) return ele;

        }
        return -1; // agar kabhi bhi 0,0 aur targetCell connected nahi hue to return -1
    }
};
int main() {
    Solution sol;
    vector<vector<int>> grid = {{0, 2}, {1, 3}};
    cout << sol.swimInWater(grid) << endl; // Output: 3
    return 0;
}
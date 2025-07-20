#include <bits/stdc++.h>
using namespace std;
int m;
int n;
vector<vector<bool>> visited;
set<vector<pair<int, int>>> st;
void dfs(int i, int j, vector<vector<int>> &grid, vector<pair<int, int>> &vec, int x, int y) {
    if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j] || !grid[i][j])
        return;                                                      // base case for DFS
    visited[i][j] = true;                                            // mark the cell as visited
    vec.push_back(make_pair(i - x, j - y));                          // store the relative position of the cell in the island shape
    vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}}; // directions for moving up, down, right, left
                                                                     // iterate through all possible directions and perform DFS recursively
    for (auto e : dir) {
        dfs(i + e.first, j + e.second, grid, vec, x, y); // dfs call to find and mark all connected land cells
    }
}
int countDistinctIslands(vector<vector<int>> &grid) {
    m = grid.size();                           // number of rows
    n = grid[0].size();                        // number of columns
    visited.resize(m, vector<bool>(n, false)); // visited matrix to track visited cells
    for (int i = 0; i < m; i++) {              // iterate through each cell in the grid
        for (int j = 0; j < n; j++) {
            if (!visited[i][j] && grid[i][j]) { // if the cell is not visited and is land (1)
                vector<pair<int, int>> vec; // vector to store the shape of the island
                dfs(i, j, grid, vec, i, j); // perform DFS to find the shape of the island
                st.insert(vec);             // insert the shape into the set to ensure uniqueness
            }
        }
    }
    return st.size(); // return the number of distinct islands
}
int main() {
    vector<vector<int>> grid = {
        {1, 1, 0, 0, 0},
        {1, 0, 0, 1, 1},
        {0, 0, 0, 1, 0},
        {0, 1, 1, 0, 0},
        {1, 0, 0, 0, 1}};
    cout << countDistinctIslands(grid) << endl; // Output the number of distinct islands
    return 0;
}

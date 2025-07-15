#include <bits/stdc++.h>
using namespace std;

struct hasher { // custom hash function for pair<int, int>
    size_t operator()(const pair<int, int>& a) const {
        return hash<int>()(a.first) ^ hash<int>()(a.second + 2);
    }
};
int m; // number of rows in the grid
int n; // number of columns in the grid
// function to traverse the grid and rot the oranges via BFS
// it returns the time taken to rot all oranges or -1 if not possible
int traverse(unordered_set<pair<int, int>, hasher>& good,
             vector<pair<int, int>>& rotten, vector<vector<int>>& grid) {
    int time = -1; // Initialize time to -1
    if (good.empty()) return 0; // If no good oranges, return 0
    queue<pair<int, int>> q; // Queue for BFS
    for (auto& p : rotten) { // Enqueue all initially rotten oranges
        q.push(p);
    }
    while (!q.empty()) {
        int size = q.size(); // size of current level
        for (int k = 0; k < size; k++) { // Process all nodes at the current level
            auto [i, j] = q.front(); // Get the front element of the queue
            q.pop(); // Remove it from the queue
            // if Adjacency cells are good oranges, rot them, erase from good set and push them to the queue
            if (i - 1 >= 0 && grid[i - 1][j] == 1) {
                grid[i - 1][j] = 2;
                q.push({i - 1, j});
                good.erase({i - 1, j});
            }
            if (i + 1 < m && grid[i + 1][j] == 1) {
                grid[i + 1][j] = 2;
                q.push({i + 1, j});
                good.erase({i + 1, j});
            }
            if (j - 1 >= 0 && grid[i][j - 1] == 1) {
                grid[i][j - 1] = 2;
                q.push({i, j - 1});
                good.erase({i, j - 1});
            }
            if (j + 1 < n && grid[i][j + 1] == 1) {
                grid[i][j + 1] = 2;
                q.push({i, j + 1});
                good.erase({i, j + 1});
            }
        }
        ++time; // Increment time after processing all nodes at the current level
    }
    return good.empty() ? time : -1; // If all good oranges are rotten, return time; otherwise, return -1
}
int orangesRotting(vector<vector<int>>& grid) {
    m = grid.size();
    n = grid[0].size();
    unordered_set<pair<int, int>, hasher> good; // Set to store good oranges
    vector<pair<int, int>> rotten; // Vector to store initially rotten oranges
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 2) // If the orange is rotten
                rotten.push_back({i, j}); // keep track of its position
            else if (grid[i][j] == 1) // If the orange is good
                good.insert({i, j}); // mark it as good
        }
    }
    int t = traverse(good, rotten, grid); // do the BFS traversal
    return t; // return the time taken to rot all oranges or -1 if not possible
}
int main() {
    vector<vector<int>> grid = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
    int result = orangesRotting(grid);
    cout << "Minimum time to rot all oranges: " << result << endl;
    return 0;
}
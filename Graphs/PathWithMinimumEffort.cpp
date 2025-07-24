#include <bits/stdc++.h>
using namespace std;
typedef pair<int, pair<int, int>> piii; 
int minimumEffortPath(vector<vector<int>>& heights) {
    int rows = heights.size(); // kitne rows hain
    int cols = heights[0].size(); // kitne columns hain
    vector<vector<int>> efforts(rows, vector<int>(cols, INT_MAX)); // Initialize efforts to all cells as infinite
    priority_queue<piii, vector<piii>, greater<piii>> pq; // Min-heap priority queue to store (effort, (row, col)) pairs
    pq.push(make_pair(0, make_pair(0, 0))); // Start with the top-left cell (0, 0) with effort 0
    efforts[0][0] = 0; // Effort to reach the starting cell
    // Directions for moving up, down, left, right
    // dirX and dirY represent the changes in row and column indices respectively
    vector<int> dirX = {1, -1, 0, 0};
    vector<int> dirY = {0, 0, -1, 1};
    pair<int, int> dest = {rows - 1, cols - 1}; // Destination cell (bottom-right corner)
    // Process the priority queue until it's empty
    while (!pq.empty()) {
        auto lowest = pq.top(); // take the cell with the lowest effort
        pair<int, int> location = lowest.second; // get the location of the cell
        int effort = lowest.first; // get the effort to reach this cell
        pq.pop(); // Remove the cell from the queue
        if (location == dest) { // If we reached the destination cell
            return effort; // Return the effort to reach the destination
        }
        for (int i = 0; i < 4; i++) { // Explore all four possible directions
            int ni = location.first + dirX[i]; // New row index after moving
            int ny = location.second + dirY[i]; // New column index after moving
            if (ni >= 0 && ni < rows && ny >= 0 && ny < cols) { // Check if the new indices are within bounds
                // currentEffort will be the maximum of the current effort and
                // the absolute difference in heights of the current cell and the new cell
                int currentEffort = max(effort, abs(heights[location.first][location.second] - heights[ni][ny]));
                // if this new effort is less than the previously recorded effort for this cell
                // push it into the priority queue
                if (currentEffort < efforts[ni][ny]) {
                    pq.push(make_pair(currentEffort, make_pair(ni, ny)));
                    efforts[ni][ny] = currentEffort;
                }
            }
        }
    }
    return -1; // If we exit the loop without finding the destination, return -1
}
int main() {
    vector<vector<int>> heights = {{1, 2, 3}, {3, 8, 4}, {5, 3, 5}};
    cout << "Minimum Effort Path: " << minimumEffortPath(heights) << endl;
    return 0;
}
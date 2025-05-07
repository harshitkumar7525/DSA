#include<bits/stdc++.h>
using namespace std;
int knapsack(int W, vector<int> &val, vector<int> &wt) {
    int n = wt.size(); //number of items
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0)); // table mein value store karne ke liye
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            if (j - wt[i - 1] < 0)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(dp[i - 1][j], val[i - 1] + dp[i - 1][j - wt[i - 1]]);
        }
    }

    return dp[n][W];
}
int main() {
    // Example usage
    int W = 50; // Maximum weight capacity of the knapsack
    vector<int> val = {60, 100, 120}; // Values of the items
    vector<int> wt = {10, 20, 30}; // Weights of the items
    int maxValue = knapsack(W, val, wt);
    cout << "Maximum value in Knapsack = " << maxValue << endl;
    // Output: Maximum value in Knapsack = 220
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

// Top-Down Approach
int knapsack1(int W, vector<int> &val, vector<int> &wt)
{
    int n = wt.size();                                    // number of items
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0)); // table mein value store karne ke liye
    // i maps with items
    // j maps with weights
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0) // agar capacity 0 hai ya koi item nahi hai
                dp[i][j] = 0;
            else if (j < wt[i]) // agar current item ko nahi daal sakte toh
                                // previous value ko hi use karlo
                dp[i][j] = dp[i - 1][j];
            else
                // current item ko skip krne aur usko lene mein jo maximum hoga usko store kr lenge
                dp[i][j] = max(dp[i - 1][j], val[i] + dp[i - 1][j - wt[i]]);
        }
    }
    return dp[n][W];
}

int helper(int W, vector<int> &val, vector<int> &wt, int n, vector<vector<int>> &dp)
{
    if (dp[n][W] != -1)
        return dp[n][W]; // agar pehle se calculated hai toh wahi return karo
    if (n == 0 || W == 0)
        return dp[n][W] = 0; // agar bag full hai ya koi item nahi hai toh return 0
    if (wt[n - 1] <= W)
    {                                                                      // agar current item to bag mein daal skte hain toh
        return dp[n][W] = max(                                             // dono ka max return karo
                   val[n - 1] + helper(W - wt[n - 1], val, wt, n - 1, dp), // usko daalo
                   helper(W, val, wt, n - 1, dp)                           // usko mat daalo
               );
    }
    else
    {
        return dp[n][W] = helper(W, val, wt, n - 1, dp); // agar current item ko nahi daal sakte toh
    }
}
// Memoization
int knapsack2(int W, vector<int> &val, vector<int> &wt)
{
    int n = wt.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));
    // Why we used n and W to generate the dp table?
    /*
    Over the recursive calls, sirf n aur W ki values change hoti hain.
    */
    helper(W, val, wt, n, dp);
    return dp[n][W];
}
int main()
{
    // Example usage
    int W = 50;                       // Maximum weight capacity of the knapsack
    vector<int> val = {60, 100, 120}; // Values of the items
    vector<int> wt = {10, 20, 30};    // Weights of the items
    int maxValue = knapsack2(W, val, wt);
    cout << "Maximum value in Knapsack = " << maxValue << endl;
    // Output: Maximum value in Knapsack = 220
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int frogJumpRecursion(int n, vector<int> &heights)
{
    if (n == 0)
        return 0; // Base case: cost to reach the first stone is 0
    int jumpOne = frogJumpRecursion(n - 1, heights) + abs(heights[n] - heights[n - 1]);
    int jumpTwo = INT_MAX;
    if (n > 1)
    {
        jumpTwo = frogJumpRecursion(n - 2, heights) + abs(heights[n] - heights[n - 2]);
    }
    return min(jumpOne, jumpTwo);
}

int frogJumpMemoization(int n, vector<int> &heights, vector<int> &dp)
{
    if (n == 0)
        return 0; // Base case: cost to reach the first stone is 0
    if (dp[n] != -1)
    {
        return dp[n]; // Return cached result if exists
    }
    int jumpOne = frogJumpMemoization(n - 1, heights, dp) + abs(heights[n] - heights[n - 1]);
    int jumpTwo = INT_MAX;
    if (n > 1)
    {
        jumpTwo = frogJumpMemoization(n - 2, heights, dp) + abs(heights[n] - heights[n - 2]);
    }
    return dp[n] = min(jumpOne, jumpTwo);
}

int frogJumpTabulation(int n, vector<int> &height)
{
    // int dp[n] = {0};
    // int first = INT_MAX;
    // int second = INT_MAX;
    // for (int i = 1; i < n; i++)
    // {
    //     first = dp[i - 1] + abs(height[i] - height[i - 1]);
    //     if (i > 1)
    //     {
    //         second = dp[i - 2] + abs(height[i] - height[i - 2]);
    //     }
    //     dp[i] = min(first, second);
    // }
    // return dp[n - 1];


    // Space Optimization
    int n = height.size();
        int first = INT_MAX;
        int second = INT_MAX;
        int prev2 = 0, prev = 0,curr =0;
        for(int i=1;i<n;i++){
            first = prev + abs(height[i]-height[i-1]);
            if(i>1){
                second = prev2 + abs(height[i]-height[i-2]);
            }
            curr=min(first,second);
            prev2=prev;
            prev=curr;
        }
        return prev;
}

int main()
{
    vector<int> heights = {10, 20, 30, 10, 30, 50, 70, 20};
    int n = heights.size();
    vector<int> dp(n, -1);
    cout << "Minimum cost (Tabulation): " << frogJumpTabulation(n, heights) << endl;
    return 0;
}
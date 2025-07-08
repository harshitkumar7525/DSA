#include<bits/stdc++.h>
using namespace std;
/*
Date: 08-07-2025
*/
int helper(vector<vector<int>> &events,int i,int k,int &n,vector<vector<int>> &dp){
    if(i>=n || k==0) return 0; // agar k=0 hai ya phir i n se bada hai, return 0
    if(dp[i][k]!=-1) return dp[i][k]; // agar dp[i][k] already calculated hai, return it
    int skip = helper(events,i+1,k,n,dp); // skip the current event
    // binary search to find the next event that can be attended after the current event
    // we need to find the first event that starts after the current event ends
    int low=i+1; // start searching from the next event
    int high=n-1; // end of the search space
    while(low<=high){
        int mid = low+(high-low)/2;
        if(events[mid][0]<=events[i][1]){ // agar mid event starts before or at the end of the current event
            // it means we cannot attend this event, so we need to search in the right half
            low=mid+1;
        } else {
            // it means we can attend this event, so we need to search in the left half
            high=mid-1;
        }
    }
    int take = events[i][2]+helper(events,low,k-1,n,dp); // take the current event and add its value to the result of the next event
    // we also decrement k by 1 since we have attended one more event
    return dp[i][k]=max(skip,take); // store the result in dp[i][k] and return the maximum of skip and take
}
int maxValue(vector<vector<int>>& events, int k) {
    if(k==0) return 0;
    sort(events.begin(),events.end());
    int n=events.size();
    vector<vector<int>> dp(n+1,vector<int> (k+1,-1)); // vector to memoize results
    return helper(events,0,k,n,dp);
}
int main() {
    vector<vector<int>> events = {{1, 2, 3}, {3, 4, 5}, {2, 3, 4}};
    int k = 2;
    cout << maxValue(events, k) << endl; // Output: 8
    return 0;
}
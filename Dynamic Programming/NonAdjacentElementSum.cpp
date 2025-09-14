// House Robber Problem
#include <bits/stdc++.h>
using namespace std;
int rob(vector<int>& nums) {
    int n = nums.size();
    if(n==0) return 0; // if no elements, return 0
    if(n==1) return nums[0]; // if only one element, return that element
    int prev=nums[0]; // max sum including the first element
    int prev2 = 0; // max sum excluding the first element
    int curr = max(prev,prev2); // max sum at current position
    for(int i=1; i<n;i++){
        int take = i-2 < 0 ? nums[i] : nums[i] + prev2; // if we take the current element
        int nonTake = prev; // if we don't take the current element
        curr=max(take,nonTake); // max sum at current position
        prev2=prev; // update prev2 to prev
        prev=curr; // update prev to curr
    }
    return prev; // return the maximum sum
}
int main()
{
    vector<int> nums = {2,7,9,3,1};
    cout<<rob(nums);
    return 0;
}
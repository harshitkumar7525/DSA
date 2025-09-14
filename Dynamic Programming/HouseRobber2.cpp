#include <bits/stdc++.h>
using namespace std;
int rob(vector<int>& nums) {
    int n = nums.size();
    if(n==0) return 0;
    if(n==1) return nums[0];
    /*
    Iteration 1:
    Leave the last house
    0 1 2 3 4 5
    - - - - -
    */
    int prev1=nums[0];
    int prev12 = 0;
    int curr = max(prev1,prev12);
    for(int i=1;i<n-1;i++){
        int take = i-2 < 0 ? nums[i] : nums[i] + prev12;
        int nonTake = prev1;
        curr=max(take,nonTake);
        prev12=prev1;
        prev1=curr;
    }
    /*
    Iteration 2:
    Leave the first house
    0 1 2 3 4 5
      - - - - -
    */
    int prev2=nums[1];
    int prev22 = 0;
    curr = max(prev2,prev22);
    for(int i=2;i<n;i++){
        int take = nums[i] + prev22;
        int nonTake = prev2;
        curr=max(take,nonTake);
        prev22=prev2;
        prev2=curr;
    }
    /*
    Since the first and last house cannot be robbed together, 
    we take the maximum of the two iterations.
    */
    return max(prev1,prev2);
}
int main()
{
    vector<int> nums = {2,3,2};
    cout<<rob(nums);
    return 0;
}
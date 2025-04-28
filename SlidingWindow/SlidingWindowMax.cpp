/*
APPROACH: 
Agar deque empty ho toh directly push_back kardo
Deque mein element push karne se pehle usse chote elements to pehle remove karo iski wajah hamesha current window ka maximum hi hoga front mein
ith element ko window se remove krne se pehle check karo abhi toh max ke equal hai ya nahi, agar hai toh deque se usse pop kardo, nahi toh kuch nhi karna
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> ans;
    int n=nums.size();
    int i=0,j=0;
    deque<int> q;
    while(j<n){
        int size = j-i+1;
        q.push_back(j);
        while(!q.empty() && nums[q.back()]>nums[q.front()]){
            q.pop_front();
        }
        if(size<k){
            j++;
        }
        else if(size==k){
            ans.push_back(nums[q.front()]);
            if(q.front()==i){
                q.pop_front();
            }
            i++;
            j++;
        }
    }
    return ans;
}
int main(){
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    vector<int> result = maxSlidingWindow(nums, k);
    for(int i=0; i<result.size(); i++){
        cout << result[i] << " "; // Output: 3 3 5 5 6 7
    }
    cout << endl;
    return 0;
}
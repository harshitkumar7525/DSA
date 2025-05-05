#include <bits/stdc++.h>
using namespace std;
// yeh helper function count karega subarrays jinka sum at most (<=) goal ho
int atMost(vector<int> &nums, int goal){
    int i = 0;      // window ka left pointer
    int sum = 0;    // current window ka sum
    int result = 0; // final result - count of valid subarrays

    for (int j = 0; j < nums.size(); j++){
        sum += nums[j]; // right end ko expand kar rahe hain

        // agar sum zyada ho gaya goal se, toh window ko chhota karo
        while (sum > goal && i <= j){
            sum -= nums[i]; // left element ko remove karo
            i++;            // left pointer ko aage badhao
        }

        // har valid window (i se j) ke liye, (j - i + 1) subarrays hoti hain
        result += j - i + 1;
    }

    return result;
}

int numSubarraysWithSum(vector<int> &nums, int goal){
    // Total subarrays jinka sum exactly goal hai
    // = (subarrays with sum ≤ goal) - (subarrays with sum ≤ goal - 1)
    return atMost(nums, goal) - atMost(nums, goal - 1);
}

int main(){
    vector<int> nums = {1, 0, 1, 0, 1};
    int goal = 2;
    cout << "Total subarrays with sum " << goal << ": " << numSubarraysWithSum(nums, goal) << endl;
    return 0;
}
// Output: Total subarrays with sum 2: 4
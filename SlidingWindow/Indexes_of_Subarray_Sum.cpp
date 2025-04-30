#include<bits/stdc++.h>
using namespace std;

/*
 * Problem:
Given an array of integers and a target sum, find the starting and ending indices of the first contiguous subarray that sums to the target. If no such subarray exists, return -1.
Consider 1-based indexing for the output.
*/

vector<int> subarraySum(vector<int>& arr, int target) {
    // code here
    vector<int> ans;
    int i = 0, j = 0;
    int n = arr.size();
    long long sum = 0;

    while (j < n) {
        sum += arr[j];

        if (sum < target) {
            j++;
        } else if (sum == target) {
            ans.push_back(i + 1);
            ans.push_back(j + 1);
            return ans;
        } else {
            while (sum > target) {
                sum -= arr[i];
                i++;
            }
            if (sum == target) { // yaha dubara check karo agar sum target ke equal hai ya nahi
                ans.push_back(i + 1);
                ans.push_back(j + 1);
                return ans;
            }
            j++;
        }
    }

    ans.push_back(-1);
    return ans;
}

int main() {
    vector<int> arr = {1, 2, 3, 7, 5};
    int target = 12;
    vector<int> result = subarraySum(arr, target);

    if (result.size() == 2) {
        cout << "Subarray found from index " << result[0] << " to " << result[1] << endl;
    } else {
        cout << "No subarray found" << endl;
    }

    return 0;
}

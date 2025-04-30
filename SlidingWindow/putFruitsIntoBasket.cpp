// Leetcode Problem 904: Fruit Into Baskets
#include<bits/stdc++.h>
using namespace std;

// Function to find the maximum number of fruits that can be collected in two baskets
int totalFruit(vector<int>& arr) {
    unordered_map<int, int> m; // har fruit type ka count store karne ke liye
    int j = 0; // window ka start pointer
    int ans = 0; // answer store karne ke liye
    int n = arr.size();

    // window end pointer i se chalega
    for (int i = 0; i < n; i++) {
        int curr = arr[i];
        m[curr]++; // current fruit ko count karo

        // agar 2 se zyada types ke fruits ho gaye, toh window chhoti karo
        if (m.size() > 2) {
            while (m.size() > 2) {
                m[arr[j]]--; // left se fruit hatao
                if (m[arr[j]] == 0) {
                    m.erase(arr[j]); // agar count 0 ho gaya toh map se hatao
                }
                j++; // window ka start pointer aage badhao
            }
        }

        ans = max(ans, i - j + 1); // max length update karo
    }

    return ans; // maximum number of fruits in two baskets return karo
}

int main() {
    vector<int> fruits1 = {1, 2, 1}; // Expected: 3 (sab fruits ek sath liye ja sakte hain)
    vector<int> fruits2 = {0, 1, 2, 2}; // Expected: 3 (subarray [1,2,2])
    vector<int> fruits3 = {1,2,3,2,2}; // Expected: 4 (subarray [2,3,2,2])

    cout << "Max fruits (Test 1): " << totalFruit(fruits1) << endl;
    cout << "Max fruits (Test 2): " << totalFruit(fruits2) << endl;
    cout << "Max fruits (Test 3): " << totalFruit(fruits3) << endl;

    return 0;
}

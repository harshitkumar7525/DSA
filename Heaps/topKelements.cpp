#include <bits/stdc++.h>
using namespace std;

// Comparator for min-heap based on frequency (second element of pair)
struct comp {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        // Return true if a's frequency is greater than b's frequency
        // This creates a min-heap where the smallest frequency is at the top
        return a.second > b.second;
    }
};

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> mp; // Map to store frequency of each element

    // Count the frequency of each number in nums
    for (auto i : nums)
        mp[i]++;

    // Min-heap to keep track of top k elements based on frequency
    priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;

    // Push all frequency pairs into the min-heap
    for (auto& pair : mp) {
        pq.push(pair);          // Push current element-frequency pair
        if (pq.size() > k)      // If heap size exceeds k,
            pq.pop();           // remove the element with smallest frequency
    }

    vector<int> ans; // To store the result: k most frequent elements

    // Extract elements from the heap (smallest frequency first)
    while (!pq.empty()) {
        ans.push_back(pq.top().first); // Add the element (not the frequency)
        pq.pop();                       // Remove it from heap
    }

    // Optional: the result is currently in ascending frequency order,
    // if order matters, reverse it to get descending frequency
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    vector<int> nums = {1, 1, 1, 2, 2, 3}; 
    int k = 2; 
    vector<int> result = topKFrequent(nums, k);
    cout << "Top " << k << " frequent elements: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}

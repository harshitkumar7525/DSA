// leetcode 2163
#include <bits/stdc++.h>
using namespace std;

#define ll long long

long long minimumDifference(vector<int>& nums) {
    int n = nums.size();
    int k = n / 3;

    // Sirf k+1 elements hi store karenge left/right ke liye
    vector<ll> leftMins(k + 1), rightMaxs(k + 1);

    // Left ke liye max heap (taaki chhote elements rakh sake)
    priority_queue<ll> maxLeftHeap;

    // Right ke liye min heap (taaki bade elements rakh sake)
    priority_queue<ll, vector<ll>, greater<ll>> minRightHeap;

    int arrptr = 0;
    ll leftSum = 0, rightSum = 0, minDiff = LLONG_MAX;

    // Pehle k elements maxHeap mein daalke leftSum nikaalo
    for (int i = 0; i < k; i++) {
        maxLeftHeap.push(nums[i]);
        leftSum += nums[i];
    }

    // Pehla prefix sum store karo
    leftMins[arrptr++] = leftSum;

    // index k se lekar n-k tak chalte hue prefix minimum sum banate jaao
    for (int i = k; i < n - k; i++) {
        if (!maxLeftHeap.empty() && nums[i] < maxLeftHeap.top()) {
            // Agar current element heap ke max se chhota hai toh replace karke sum update karo
            leftSum += nums[i] - maxLeftHeap.top();
            maxLeftHeap.pop();
            maxLeftHeap.push(nums[i]);
        }
        leftMins[arrptr++] = leftSum;
    }

    // Last ke k elements right ke liye minHeap mein daalo
    for (int i = n - 1; i >= n - k; i--) {
        minRightHeap.push(nums[i]);
        rightSum += nums[i];
    }

    // Right maxs ke last index par initial sum daal do
    arrptr = k;
    rightMaxs[arrptr--] = rightSum;

    // Reverse mein chalte hue right side ke largest k elements ka sum store karte jaao
    for (int i = n - k - 1; i > k - 1; i--) {
        if (!minRightHeap.empty() && nums[i] > minRightHeap.top()) {
            // Agar current element heap ke min se bada hai toh replace karke sum update karo
            rightSum += nums[i] - minRightHeap.top();
            minRightHeap.pop();
            minRightHeap.push(nums[i]);
        }
        rightMaxs[arrptr--] = rightSum;
    }

    // Ab difference calculate karke minimum nikaal lo
    for (int i = 0; i <= k; i++) {
        minDiff = min(minDiff, leftMins[i] - rightMaxs[i]);
    }

    return minDiff;
}
int main() {
    // Sample input (n = 9, k = 3)
    vector<int> nums = {3, 1, 4, 1, 5, 9, 2, 6, 5};

    // Function call
    long long result = minimumDifference(nums);

    // Output
    cout << "Minimum difference: " << result << endl;

    return 0;
}

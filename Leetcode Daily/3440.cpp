/*
10th July 2025
*/
#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>

int maxFreeTime(int eventTime, vector<int>& start, vector<int>& end) {
    int n = start.size();

    // Step 1: Gaps calculate karo (total n+1 honge)
    // - gap[0] = start[0] - 0
    // - gap[1] = start[1] - end[0]
    // - ...
    // - gap[n] = eventTime - end[n-1]
    vector<int> actualGaps;
    actualGaps.push_back(start[0]); // gap[0]

    for (int i = 1; i < n; ++i) {
        actualGaps.push_back(start[i] - end[i - 1]); // gap[i]
    }

    actualGaps.push_back(eventTime - end[n - 1]); // gap[n]

    // Step 2: Gaps ko sort karo descending order mein (for greedy choice)
    // - Har gap ke sath uska index bhi store karo
    // - Ye sortedGaps use honge jab kisi meeting ko hata ke koi aur gap use kar
    // sakein
    vector<pii> sortedGaps; // {gapSize, gapIndex}
    for (int i = 0; i < actualGaps.size(); ++i) {
        sortedGaps.push_back({actualGaps[i], i});
    }
    sort(sortedGaps.rbegin(), sortedGaps.rend()); // descending sort

    int maxTime = 0; // final answer

    // Step 3: Har meeting ke liye check karo:
    // - adjacent gaps ka sum nikalo: gap[i] + gap[i+1]
    // - check karo kya koi dusra non-adjacent gap hai jisme hum meeting ka time
    // recover kar saken
    for (int i = 0; i < n; ++i) {
        int duration = end[i] - start[i]; // meeting ka duration
        int adjGapSum = 0;

        // Adjacent gaps collect karo
        if (i < actualGaps.size())
            adjGapSum += actualGaps[i]; // gap[i]
        if (i + 1 < actualGaps.size())
            adjGapSum += actualGaps[i + 1]; // gap[i+1]

        bool replaced = false;

        // Step 3a: Sorted gaps mein dekho koi non-adjacent gap hai jo meeting
        // ke time se bada ho
        for (auto& [gapSize, gapIdx] : sortedGaps) {
            if (gapIdx != i && gapIdx != i + 1 && gapSize >= duration) {
                // Hum meeting hata ke ye extra gap use kar rahe hain
                // Total free time = adjacentGapSum + duration (kyunki hum
                // meeting ka time recover kar liya)
                maxTime = max(maxTime, adjGapSum + duration);
                replaced = true;
                break; // greedy: first valid large-enough gap use karo
            }
        }

        // Step 3b: Agar koi aisa gap nahi mila, toh simply adjacent gaps ka sum
        // hi free time hoga
        if (!replaced) {
            maxTime = max(maxTime, adjGapSum);
        }
    }

    return maxTime;
}

int main() {
    int eventTime = 10;
    vector<int> start = {1, 3, 5};
    vector<int> end = {2, 4, 6};

    int result = maxFreeTime(eventTime, start, end);
    cout << "Maximum free time: " << result
         << endl; // Output: Maximum free time: 8
    return 0;
}
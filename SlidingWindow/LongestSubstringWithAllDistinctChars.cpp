#include<bits/stdc++.h>
using namespace std;

// Function to find length of longest substring without repeating characters
int lengthOfLongestSubstring(string s) {
    unordered_set<char> st; // unique characters ko store karne ke liye set
    int i = 0;
    int n = s.length();
    int ans = 0;

    // Sliding window approach
    for(int j = 0; j < n; j++) {
        // Agar character already set mein hai toh window ka left part move karo
        while(st.find(s[j]) != st.end()) {
            st.erase(s[i++]); // purana character hatao aur left pointer aage badhao
        }
        st.insert(s[j]); // naya character add karo
        ans = max(ans, j - i + 1); // max length update karo
    }
    return ans; // longest substring ki length return karo
}

int main() {
    string s = "abcabcbb";
    cout << lengthOfLongestSubstring(s) << endl; // Output: 3 (substring "abc")

    string s2 = "bbbbb";
    cout << lengthOfLongestSubstring(s2) << endl; // Output: 1 (substring "b")

    return 0;
}

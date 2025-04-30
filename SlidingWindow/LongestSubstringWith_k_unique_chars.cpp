#include <bits/stdc++.h>
using namespace std;
int longestKSubstr(string &s, int k){
    int ans = -1; // Initialize answer to -1
    // to handle the case when no substring is found
    int i = 0, j = 0; 
    int n = s.length();
    unordered_map<char, int> m; // Map to store the frequency of characters
    while (j < n){
        m[s[j]]++; // Increment the frequency of the current character
        int size = m.size();
        if (size < k){ // agar window mein k se kam unique characters hain
            j++; // toh window ko expand karo
        }
        else if (size == k){ // agar window mein k unique characters hain
            ans = max(ans, j - i + 1); // update the answer
            j++; // window ko expand karo
        }
        else{ // agar window mein k se zyada unique characters hain
            while (m.size() > k){ // jab tak window mein k se zyada unique characters hain
                m[s[i]]--; // character at index i ka frequency decrement karo
                if (m[s[i]] == 0){ // agar frequency 0 ho gaya toh us character ko map se hata do
                    m.erase(s[i]);
                }
                i++; // window ko shrink karo
            }
            j++; // window ko expand karo
        }
    }
    return ans;
}
int main(){
    string s = "aabacbebebe";
    int k = 3;
    cout << longestKSubstr(s, k) << endl;
    return 0;
}
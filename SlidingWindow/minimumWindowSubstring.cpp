#include<bits/stdc++.h>
using namespace std;
string minWindow(string &s, string &t) {
    unordered_map<char, int> m;

    // Step 1: t ke characters ka frequency map banao
    for (auto c : t) {
        m[c]++;
    }

    int count = m.size(); // unique characters ki count jo match karne hain
    int n = s.length();
    int i = 0, j = 0;     // sliding window ke two pointers
    int minLen = INT_MAX; // ab tak ki sabse chhoti valid window ka length
    int start = 0;        // us window ka starting index

    // Step 2: sliding window start karo
    while (j < n) {
        // Agar current character s[j] required hai (t mein tha)
        if (m.find(s[j]) != m.end()) {
            m[s[j]]--; // uska count kam karo
            if (m[s[j]] == 0) {
                count--; // agar count 0 ho gaya, matlab ye character poora match ho gaya
            }
        }

        // Step 3: Jab sab characters match ho jaaye (count == 0)
        while (count == 0) {
            // current window ka size check karo aur update karo agar chhoti hai
            if (j - i + 1 < minLen) {
                minLen = j - i + 1;
                start = i;
            }

            // ab window ko chhota karne ki koshish karo (left se)
            if (m.find(s[i]) != m.end()) {
                m[s[i]]++; // character wapas map mein add karo
                if (m[s[i]] == 1) {
                    count++; // agar kisi character ka count > 0 ho gaya, to match incomplete ho gaya
                }
            }
            i++; // left pointer aage badhao
        }

        j++; // right pointer aage badhao
    }

    // agar koi valid window mili hi nahi to empty string return karo
    return minLen == INT_MAX ? "" : s.substr(start, minLen);
}

int main(){
    string s="totmtaptat";
    string t="tta";
    cout<<minWindow(s,t);
    return 0;
}
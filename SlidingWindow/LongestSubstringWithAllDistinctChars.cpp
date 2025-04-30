#include<bits/stdc++.h>
using namespace std;
int lengthOfLongestSubstring(string s) {
    unordered_set<char> st;
    int i=0;
    int n=s.length();
    int ans = 0;
    for(int j=0;j<n;j++){
        while(st.find(s[j])!=st.end()){
            st.erase(s[i++]);
        }
        st.insert(s[j]);
        ans=max(ans,j-i+1);
    }
    return ans;
}
int main(){
    string s = "abcabcbb";
    cout << lengthOfLongestSubstring(s) << endl; // Output: 3 (substring "abc")

    string s2 = "bbbbb";
    cout << lengthOfLongestSubstring(s2) << endl; // Output: 1 (substring "b")
    return 0;
}
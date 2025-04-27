#include <bits/stdc++.h>
using namespace std;

int search(string &pat, string &txt) {
    // code here
    int k = pat.length(); // window ki size
    int n=txt.length(); // string ki size
    int i=0,j=0; // i=0, j=0 se start karte hain
    int ans=0; // answer ko 0 se initialize karte hain
    unordered_map<char,int> m; // map mein pattern ke characters ki frequency store karte hain
    for(auto c:pat){
        m[c]++;
    }
    int count=m.size(); // unique characters ki count ko store karte hain
    while(j<n){
        int size = j-i+1; //window ki current size
        //calculations
        char curr = txt[j]; // current character ko store karte hain
        if(m.find(curr)!=m.end()){ // agar current character map mein hai
            m[curr]--; // uski frequency ko decrease karte hain
            if(m[curr]==0){ // agar frequency 0 ho gayi hai
                count--; // toh unique characters ki count ko decrease karte hain
            }
        }
        if(size<k){ // agar window ki size pattern se choti hai to usse expand karte hain
            j++;
        }
        else if(size==k){ // agar window ki size pattern ke barabar hai
            //find out answer
            if(count==0) ans++; // agar unique characters ki count 0 hai toh iska matlab pattern mil gaya hai
            // window ko slide karne se pehle hame ith character ke calculations ko hatane hain
            if(m.find(txt[i])!=m.end()){  // agar ith character map mein hai
                m[txt[i]]++; // toh uski frequency ko increase karte hain
                if(m[txt[i]]==1) count++; // agr frequency 1 ho gayi hai toh unique characters ki count ko increase karte hain
            }
            //slide the window
            i++;
            j++;
        }
    }
    return ans;
}
//main function to test the search function
int main(){
    string txt = "forxxorfxdofr"; // input string
    string pat = "for"; // pattern to search
    cout << search(pat, txt) << endl; // Output: 3

    string txt2 = "aabbcc"; // another input string
    string pat2 = "abc"; // another pattern to search
    cout << search(pat2, txt2) << endl;
    return 0;
}
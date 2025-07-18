#include<bits/stdc++.h>
using namespace std;
int wordLadderLength(string beginWord, string endWord,vector<string>& wordList) {
    unordered_set<string> words(wordList.begin(),wordList.end()); // Convert vector to unordered_set for O(1) lookups
    queue<pair<string,int>> q; // queue ki help se BFS karenge, jis mein hm string aur level store karenge
    q.push({beginWord,1});  // Start with the beginWord at level 1
    words.erase(beginWord); // Remove the beginWord from the set to avoid cycles
    while(!q.empty()){  // jab tak queue khali nahi hoti
        auto& [curr,level] = q.front(); // Get the front element of the queue
        q.pop(); // Pop the front element from the queue
        if(curr==endWord) return level; // Agar current word endWord ke barabar hai toh level return karo
        for(int i=0;i<curr.size();i++){ // Loop through each character of the current word
            char original = curr[i]; // Store the original character
            for(char ch='a';ch<='z';ch++){ // Try replacing the character with every letter from 'a' to 'z'
                if(ch!=original) curr[i]=ch; // Replace the character, if it's not the original character
                if(words.find(curr)!=words.end()){ // Agar modified word words set mein hai toh
                    words.erase(curr); // Remove it from the set to avoid cycles
                    q.push({curr,level+1}); // Push the modified word and incremented level into the queue
                }
            }
            curr[i]=original; // Restore the original character before the next iteration
        }
    }
    return 0; // Agar endWord nahi mila toh 0 return karo
}
int main() {
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    int result = wordLadderLength(beginWord, endWord, wordList);
    cout << "Length of shortest transformation sequence: " << result << endl;
    return 0;
}
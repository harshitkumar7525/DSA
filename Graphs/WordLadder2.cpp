#include <bits/stdc++.h>
using namespace std;

// depthMap har word ka level (BFS mein kitne steps mein aaya) track karta hai
unordered_map<string, int> depthMap;

// ---------- DFS function ----------
// Ye function recursively endWord se beginWord tak backtrack karta hai
// Sirf unhi words ko consider karta hai jo ek step pehle aaye hon BFS ke hisaab se
void dfs(const string& word, const string& beginWord, vector<string>& seq, vector<vector<string>>& ans) {
    // Agar beginWord tak pahuch gaye to sequence ko reverse karke ans mein store kar lo
    if (word == beginWord) {
        reverse(seq.begin(), seq.end()); // sequence reverse kyunki hum end se start kar rahe hain
        ans.push_back(seq);              // valid path mil gaya
        reverse(seq.begin(), seq.end()); // original order wapas la rahe hain for backtracking
        return;
    }

    int steps = depthMap[word];
    string temp = word;

    // Har position par har character try karo (a-z)
    for (int i = 0; i < temp.size(); ++i) {
        char original = temp[i];
        for (char ch = 'a'; ch <= 'z'; ++ch) {
            temp[i] = ch;
            // Agar temp ek valid word hai jo previous step mein tha
            if (depthMap.count(temp) && depthMap[temp] + 1 == steps) {
                seq.push_back(temp);         // us word ko sequence mein dalo
                dfs(temp, beginWord, seq, ans); // recursive DFS call karo
                seq.pop_back();              // backtrack karo
            }
        }
        temp[i] = original; // original character restore karo
    }
}

// ---------- Main function to find all ladders ----------
vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    vector<vector<string>> ans;

    // Word set bana lo for fast lookup (O(1) mein check karne ke liye)
    unordered_set<string> wordSet(wordList.begin(), wordList.end());

    // Agar endWord hi list mein nahi hai, to koi path possible nahi
    if (!wordSet.count(endWord)) return ans;

    // BFS setup
    queue<string> q;
    q.push(beginWord);
    depthMap[beginWord] = 1; // start word ka level 1 hai
    wordSet.erase(beginWord); // visited mark kar diya

    // ---------- BFS loop ----------
    // Goal: har word ka minimum step count (shortest path) nikalna
    while (!q.empty()) {
        string word = q.front();
        q.pop();
        int steps = depthMap[word];

        // Agar endWord mil gaya, to aur deep jaane ki zarurat nahi
        if (word == endWord) break;

        // Har position pe har character try karo
        for (int i = 0; i < word.size(); ++i) {
            char original = word[i];
            for (char ch = 'a'; ch <= 'z'; ++ch) {
                word[i] = ch;
                // Agar valid word mila jo abhi tak visit nahi hua
                if (wordSet.count(word)) {
                    q.push(word);                  // BFS ke next level mein daal do
                    wordSet.erase(word);           // visited mark kar lo
                    depthMap[word] = steps + 1;    // step count update karo
                }
            }
            word[i] = original; // character restore karo
        }
    }

    // ---------- DFS call ----------
    // Agar BFS ke baad endWord reachable hai to DFS chalao
    if (depthMap.count(endWord)) {
        vector<string> seq = {endWord}; // sequence mein endWord se start kar rahe hain
        dfs(endWord, beginWord, seq, ans);
    }

    return ans; // final answer return karo
}

// ---------- MAIN FUNCTION ----------
int main() {
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};

    // Function call
    vector<vector<string>> ladders = findLadders(beginWord, endWord, wordList);

    // Output print karna
    cout << "All shortest transformation sequences:\n";
    for (const auto& path : ladders) {
        for (const auto& word : path) {
            cout << word << " ";
        }
        cout << "\n";
    }

    return 0;
}

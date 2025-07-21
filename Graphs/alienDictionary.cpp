#include<bits/stdc++.h>
using namespace std;

// Alien Dictionary order find karna hai based on given dictionary (words)
string findOrder(vector<string> &words) {
    queue<int> q;

    // Step 1: Sare unique characters ko ek set mein daal rahe hain
    // Taaki pata chale ki total kitne distinct letters hain
    unordered_set<char> unique_chars;
    for (auto &s : words) {
        unique_chars.insert(s.begin(), s.end());
    }

    // Step 2: Har character ko ek index assign kar rahe hain
    // Ye mapping isliye kar rahe hain taaki graph ke node number use kar sake
    unordered_map<char, int> char_to_index;
    unordered_map<int, char> index_to_char;
    int index = 0;
    for (char c : unique_chars) {
        char_to_index[c] = index;
        index_to_char[index] = c;
        index++;
    }

    int k = unique_chars.size(); // total unique characters
    vector<int> in(k, 0); // in-degree array: har node ka in-degree count
    int n = words.size();
    vector<vector<int>> adj(k); // adjacency list for the graph

    // Step 3: Graph banana hai based on character order jo humein words se milta hai
    for (int i = 0; i < n - 1; i++) {
        string &w1 = words[i];
        string &w2 = words[i + 1];
        int l1 = w1.size();
        int l2 = w2.size();
        int l = 0;

        // Do words ke pehle mismatching character pe edge banate hain
        // Jaise "abc" aur "abd" mein c < d, toh edge c -> d
        while (l < l1 && l < l2) {
            if (w1[l] != w2[l]) {
                int u = char_to_index[w1[l]];
                int v = char_to_index[w2[l]];
                adj[u].push_back(v); // u -> v means u comes before v
                in[v]++; // v ka in-degree badh gaya
                break;
            }
            l++;
        }

        // Special case: agar second word puri tarah pehle word ka prefix hai, toh invalid order
        if (l == l2 && l1 > l2)
            return "";
    }

    // Step 4: Topological Sort using Kahn’s Algorithm
    // Sabse pehle un nodes ko queue mein daalo jinka in-degree 0 hai
    string ans = "";
    for (int i = 0; i < k; i++) {
        if (in[i] == 0) {
            q.push(i);
        }
    }

    // Queue se nikaalte jao aur answer build karte jao
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        ans += index_to_char[curr]; // index ko wapas character mein convert kiya

        // Har adjacent node ka in-degree reduce karo
        for (auto &n : adj[curr]) {
            if (--in[n] == 0) {
                q.push(n);
            }
        }
    }

    // Agar answer mein saare characters aa gaye, toh return karo
    // Nahi toh iska matlab cycle hai ya galat input
    return ans.size() == k ? ans : "";
}

int main() {
    // Sample Input 1
    vector<string> words1 = {"baa", "abcd", "abca", "cab", "cad"};

    // Sample Input 2
    vector<string> words2 = {"caa", "aaa", "aab"};

    // Order find karo
    string order1 = findOrder(words1);
    string order2 = findOrder(words2);

    // Output print karo
    cout << "Order for words1: " << (order1.empty() ? "Invalid order" : order1) << endl;
    cout << "Order for words2: " << (order2.empty() ? "Invalid order" : order2) << endl;

    return 0;
}

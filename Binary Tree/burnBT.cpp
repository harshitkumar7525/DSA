#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
int minTime(TreeNode* root, int target) {
    unordered_map<TreeNode*, TreeNode*>
        mp; // parent map mein hr node ka parent store karenge
    queue<TreeNode*> q;
    q.push(root);
    TreeNode* tar; // target node ko store karne ke liye
    mp[root] = NULL;
    while (!q.empty()) { // level order traversal se map fill karenge
        int size = q.size();
        for (int i = 0; i < size; i++) {
            TreeNode* curr = q.front();
            if (curr->val == target) {
                tar = curr;
            }
            q.pop();
            if (curr->left) {
                mp[curr->left] = curr;
                q.push(curr->left);
            }
            if (curr->right) {
                mp[curr->right] = curr;
                q.push(curr->right);
            }
        }
    }
    unordered_set<TreeNode*>
        burnt; // visited set mein visited nodes ko store karenge
    q.push(tar);
    burnt.insert(tar); // time=0 prr yeh already burnt hai
    int time = -1;
    while (!q.empty()) {
        int size = q.size();
        time++;
        for (int i = 0; i < size; i++) {
            TreeNode* curr = q.front();
            q.pop();
            if (mp[curr] && burnt.find(mp[curr]) == burnt.end()) {
                // parent ko check karo
                // agar parent nahi hai toh usko bhi burnt kar do
                // aur queue mein daal do
                q.push(mp[curr]);
                burnt.insert(mp[curr]);
            }
            if (curr->left && burnt.find(curr->left) == burnt.end()) {
                // left child ko check karo
                // agar left hai aur already burnt nahi hai toh usko bhi burnt
                // kar do
                q.push(curr->left);
                burnt.insert(curr->left);
            }
            if (curr->right && burnt.find(curr->right) == burnt.end()) {
                // right child ko check karo
                // agar right hai aur already burnt nahi hai toh usko bhi burnt
                // kar do
                q.push(curr->right);
                burnt.insert(curr->right);
            }
        }
    }
    return time;
}
int main() {
    // Create a binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    // Find nodes at distance K from a target node
    int target = 2; // Target node value
    int result = minTime(root, target);
    cout << result << endl;
    return 0;
}
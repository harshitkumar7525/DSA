#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    unordered_map<TreeNode*, TreeNode*>
        parent; // parent map mein hm hr node ka parent store karenge
    queue<TreeNode*> q;
    int d = -1; // distance variable
    q.push(root);
    parent[root] = NULL;
    unordered_set<TreeNode*>
        v; // visited set mein hm visited nodes ko store karenge
    while (!q.empty()) {
        int size = q.size(); // level order traversal
        for (int i = 0; i < size; i++) {
            TreeNode* curr = q.front();
            q.pop();
            if (curr->left) {
                q.push(curr->left);
                parent[curr->left] = curr;
            }
            if (curr->right) {
                q.push(curr->right);
                parent[curr->right] = curr;
            }
        }
    }
    // q empty ho gaya hai ab hum target node se start karenge aur uske parent
    // ko bhi store karenge
    q.push(target);
    vector<int> ans;  // answer vector
    v.insert(target); // target ko visited set mein daal do
    while (!q.empty()) {
        d++; // distance ko increment karo
        int size = q.size();
        if (d == k) { // agar distance k hai toh ans mein daal do
            for (int i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();
                ans.push_back(curr->val);
            }
            break;
        }
        for (int i = 0; i < size; i++) { // level order traversal
            TreeNode* curr = q.front();
            q.pop();
            if (curr->left && v.find(curr->left) == v.end()) {
                q.push(curr->left);
                v.insert(curr->left);
            }
            if (curr->right && v.find(curr->right) == v.end()) {
                q.push(curr->right);
                v.insert(curr->right);
            }
            if (parent[curr] && v.find(parent[curr]) == v.end()) {
                q.push(parent[curr]);
                v.insert(parent[curr]);
            }
        }
    }
    return ans;
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
    TreeNode* target = root->left; // Example target
    int k = 2;
    vector<int> result = distanceK(root, target, k);
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}
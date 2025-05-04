#include<bits/stdc++.h>
using namespace std;
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// Function to find the level with maximum sum in a binary tree
int maxLevelSum(TreeNode* root) {
    int level = 1;
    int maxSum = INT_MIN;
    int ans = 1;
    queue<TreeNode*> q;
    q.push(root);
    q.push(nullptr);
    int curr = 0;
    while (!q.empty()) {
        TreeNode* temp = q.front();
        q.pop();
        if (temp == nullptr && !q.empty()) {
            q.push(nullptr);
            if (curr > maxSum) {
                maxSum = curr;
                ans = level;
            }
            curr = 0;
            level++;
        } else if (temp == nullptr && q.empty()) {
            break;
        } else {
            if (temp != nullptr) {
                curr += temp->val;
            }
        }
        if (temp != nullptr) {
            if (temp->left != nullptr) {
                q.push(temp->left);
            }
            if (temp->right != nullptr) {
                q.push(temp->right);
            }
        }
    }
    if (curr > maxSum) {
        maxSum = curr;
        ans = level;
    }
    return ans;
}
int main() {
    /*
     Constructing a binary tree
             -100
            /     \
          -200     -300
          /  \     /
        -20  -5  -10
    */
    TreeNode* root = new TreeNode(-100);
    root->left = new TreeNode(-200);
    root->right = new TreeNode(-300);
    root->left->left = new TreeNode(-20);
    root->left->right = new TreeNode(-5);
    root->right->left = new TreeNode(-10);

    cout << "Level with maximum sum: " << maxLevelSum(root) << endl; // Output: 3
    return 0;
}
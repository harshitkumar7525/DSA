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
    int level = 1; // Start from level 1
    int maxSum = INT_MIN; // maxSum ko initial value INT_MIN se set kiya gaya hai
    if (root == NULL) return 0; // Agar root NULL hai toh 0 return karo
    int ans = 1; //ans ko initial value 1 se set kiya gaya hai
    queue<TreeNode*> q; // Queue ka use karke level order traversal karne ke liye
    // Queue ko initialize karo
    q.push(root);
    while (!q.empty()) { // Jab tak queue khali nahi hoti
        int size = q.size(); // Current level ke nodes ki sankhya
        int curr = 0; // Current level ka sum 
        for(int i=0;i<size;i++){ // ek iteration mein ek  level ke nodes process honge
            TreeNode* temp = q.front(); // Queue ke front se node ko nikaalo
            q.pop(); // Queue se node ko hata do
            // Current node ka value ko sum mein add karo
            curr+=temp->val;
            if(temp->left != NULL){ // Agar left child hai toh usse queue mein daal do
                q.push(temp->left);
            }
            if(temp->right != NULL){ // Agar right child hai toh usse queue mein daal do
                q.push(temp->right);
            }
        }
        if(curr>maxSum){ // Agar current level ka sum maxSum se bada hai
            maxSum=curr; // maxSum ko update karo
            ans=level; // ans ko current level se update karo
        }
        level++; // Level ko increment karo
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
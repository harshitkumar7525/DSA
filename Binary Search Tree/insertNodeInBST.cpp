#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data) : val(data), left(nullptr), right(nullptr) {}
};
TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) return new TreeNode(val); // agar root null hai to naya node banake return karte hain
        TreeNode* curr = root; // current node ko root se initialize karte hain
        while(true){ // jab tak naya node insert nahi ho jata tab tak loop chalta hai
            if(curr->val < val){ // agar val current node ke value se bada hai to right subtree mein jaate hain
                if(!curr->right){ // agar right child null hai to naya node wahan insert karte hain
                    curr->right=new TreeNode(val);
                    break;
                } else { // agar right child null nahi hai to current node ko right mein move karte hain
                    curr=curr->right;
                }
            } else { // agar val current node ke value se chhota hai to left subtree mein jaate hain
                if(!curr->left){  // agar left child null hai to naya node wahan insert karte hain
                    curr->left=new TreeNode(val);
                    break;
                } else { // agar left child null nahi hai to current node ko left mein move karte hain
                    curr=curr->left;
                }
            }
    }
    return root;
}
int main() {
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);
    root->right->right = new TreeNode(18);
    int val = 6;
    root = insertIntoBST(root, val);
    // Function to print the level order traversal of the BST
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        cout << node->val << " ";
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
    return 0;
}
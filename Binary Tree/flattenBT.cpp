#include<bits/stdc++.h>
using namespace std;

// Binary Tree ka node structure
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    
    // Constructor to initialize node
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to flatten the binary tree into linked list in-place
void flatten(TreeNode* root) {
    TreeNode* curr = root;  // current node ko point karega
    TreeNode* prev;

    while(curr) {
        // Agar current node ka left child exist karta hai
        if(curr->left) {
            prev = curr->left;
            
            // Left subtree ke rightmost node tak jao
            while(prev->right) {
                prev = prev->right;
            }

            // Rightmost node ke right me current node ka right subtree jod do
            prev->right = curr->right;

            // Current node ka left subtree ko right me shift karo
            curr->right = curr->left;
            curr->left = NULL;  // Left ko null kar do as per linked list structure
        }

        // Aage badho right pointer ke through
        curr = curr->right;
    }
}

int main() {
    // Binary tree create kar rahe hain
    /*
            1
           / \
          2   5
         / \   \
        3   4   6
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);

    // Flatten function call karo
    flatten(root);

    // Flattened tree ko print karo (Linked List ban gaya hai right pointers se)
    TreeNode* curr = root;
    while (curr) {
        cout << curr->val << " ";  // Sirf right child follow karke print kar rahe hain
        curr = curr->right;
    }
    cout << endl;

    return 0;
}

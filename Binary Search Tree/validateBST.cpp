#include <bits/stdc++.h>
using namespace std;

// Binary tree ka node structure
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Helper function to check valid BST using range [low, high]
bool helper(TreeNode* root, long long low, long long high) {
    if (!root) return true; // NULL node valid hota hai (base case)

    // Agar current node ka value range ke andar hai, tabhi valid hai
    if (low < root->val && root->val < high) {
        // Left subtree ke liye upper bound current node se chhota hoga
        // Right subtree ke liye lower bound current node se bada hoga
        return helper(root->left, low, root->val) &&
               helper(root->right, root->val, high);
    } else {
        return false; // Agar range violate hui, toh BST nahi hai
    }
}

// Main function jise user call karega
bool isValidBST(TreeNode* root) {
    return helper(root, LLONG_MIN, LLONG_MAX); // Start with full range
}

// Inorder print karne ke liye (optional)
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    /*
       Valid BST:
               5
              / \
             3   7
            / \   \
           2   4   8
    */
    TreeNode* root1 = new TreeNode(5);
    root1->left = new TreeNode(3);
    root1->right = new TreeNode(7);
    root1->left->left = new TreeNode(2);
    root1->left->right = new TreeNode(4);
    root1->right->right = new TreeNode(8);

    /*
       Invalid BST:
               5
              / \
             3   7
            / \
           2   6  <- Invalid, 6 > 5 but placed in left subtree
    */
    TreeNode* root2 = new TreeNode(5);
    root2->left = new TreeNode(3);
    root2->right = new TreeNode(7);
    root2->left->left = new TreeNode(2);
    root2->left->right = new TreeNode(6);

    // Testing both trees
    cout << "Tree 1 is " << (isValidBST(root1) ? "a valid" : "an invalid") << " BST.\n";
    cout << "Tree 2 is " << (isValidBST(root2) ? "a valid" : "an invalid") << " BST.\n";

    return 0;
}

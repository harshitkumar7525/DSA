#include <bits/stdc++.h>
using namespace std;

// TreeNode structure for BST
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// LCA finder in BST
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    // Agar root null hai ya root hi p ya q me se ek hai to wahi LCA hoga
    if (!root || root == p || root == q) {
        return root;
    }

    // Dono nodes root se bade hai -> right subtree me LCA hoga
    if (root->val < p->val && root->val < q->val) {
        return lowestCommonAncestor(root->right, p, q);
    }
    
    // Dono nodes root se chhote hai -> left subtree me LCA hoga
    if (root->val > p->val && root->val > q->val) {
        return lowestCommonAncestor(root->left, p, q);
    }

    // Yaha aake iska matlab hai ki p aur q alag-alag direction me hai -> root hi LCA hoga
    return root;
}

// Inorder traversal (for visualization)
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    /*
            6
           / \
          2   8
         / \ / \
        0  4 7  9
          / \
         3   5
    */
    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);
    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);

    TreeNode* p = root->left;          // 2
    TreeNode* q = root->left->right;  // 4

    TreeNode* lca = lowestCommonAncestor(root, p, q);
    cout << "Lowest Common Ancestor of " << p->val << " and " << q->val << " is: " << lca->val << endl;

    return 0;
}

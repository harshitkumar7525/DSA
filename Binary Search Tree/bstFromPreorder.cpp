#include <bits/stdc++.h>
using namespace std;

// Binary Tree ka Node structure
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Helper function jiska kaam hai BST banana preorder array se
TreeNode* helper(vector<int>& preorder, int &idx, int ub, int& n) {
    // Base case:
    // 1. Agar index array ke bahar chala gaya
    // 2. Ya current element upper bound se bada hai => wo is subtree ka part nahi
    if(idx == n || preorder[idx] > ub) return NULL;

    // Naya node banao preorder ke current index se
    TreeNode* curr = new TreeNode(preorder[idx++]);

    // Left child banate waqt upper bound current node ka value banega
    curr->left = helper(preorder, idx, curr->val, n);

    // Right child banate waqt upper bound wahi rahega jo parent ne diya tha
    curr->right = helper(preorder, idx, ub, n);

    return curr; // Current node return karo jiske left-right subtree ban chuke hain
}

// Main function jo user call karega
TreeNode* bstFromPreorder(vector<int>& preorder) {
    int idx = 0;
    int n = preorder.size();
    return helper(preorder, idx, INT_MAX, n); // Shuruat mein koi upper limit nahi hoti
}

// Inorder traversal (used to check BST correctness => should be sorted)
void inorder(TreeNode* root) {
    if(!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    // Test case: preorder array diya hua hai
    vector<int> preorder = {8, 5, 1, 7, 10, 12};

    // BST banate hain
    TreeNode* root = bstFromPreorder(preorder);

    // Inorder traversal print karte hain (sorted aani chahiye)
    cout << "Inorder traversal of constructed BST: ";
    inorder(root);
    cout << endl;

    return 0;
}

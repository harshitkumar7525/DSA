#include <bits/stdc++.h>
using namespace std;

// Binary Tree ka structure
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Morris Inorder Traversal based Kth Smallest Element finder
int kthSmallest(TreeNode* root, int k) {
    int count = 0;      // Kitne nodes visit kiye, track karne ke liye
    int res = -1;       // Answer store karne ke liye
    TreeNode* curr = root;

    // Jab tak current node null nahi hota, loop chalta rahega
    while (curr) {
        // Agar left child nahi hai toh current node visit karo
        if (!curr->left) {
            count++;
            if (count == k) res = curr->val; // Agar k-th node mil gaya
            curr = curr->right; // Right child pe move karo
        } else {
            // Left subtree ka inorder predecessor dhundo
            TreeNode* pre = curr->left;
            while (pre->right && pre->right != curr) {
                pre = pre->right;
            }

            // Agar thread (temporary link) nahi hai, toh usse banao
            if (!pre->right) {
                pre->right = curr; // Thread banate hai
                curr = curr->left; // Left child pe move karte hai
            } 
            // Agar thread already bana hua hai, toh usse tod do
            else {
                pre->right = NULL; // Thread hatao
                count++;
                if (count == k) res = curr->val; // k-th smallest element mila?
                curr = curr->right; // Right subtree me jao
            }
        }
    }
    return res;
}

// Inorder traversal just for verification (optional)
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    // BST create karte hai:
    /*
            5
           / \
          3   6
         / \
        2   4
       /
      1
    */
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->left->left->left = new TreeNode(1);

    // Inorder traversal dekh lete hai (sorted output)
    cout << "Inorder of BST: ";
    inorder(root);
    cout << "\n";

    // Kth smallest find karte hai
    int k = 3;
    int result = kthSmallest(root, k);
    cout << k << "th smallest element is: " << result << endl;

    return 0;
}

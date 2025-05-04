#include <bits/stdc++.h>
using namespace std;

// TreeNode structure define kiya
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Helper function: Do trees identical hain ya nahi check karta hai
bool isIdentical(TreeNode* root, TreeNode* subRoot) {
    // Agar dono null hain to identical hai
    if (root == NULL && subRoot == NULL) {
        return true;
    }
    // Agar koi ek null hai ya data match nahi kar raha to identical nahi hain
    else if (root == NULL || subRoot == NULL || root->val != subRoot->val) {
        return false;
    } else {
        // Recursively left aur right subtree ko check karo
            if(!isIdentical(root->left, subRoot->left)){ //agar left identical nhi hai to false return kardo
                return false;
            } else if(!isIdentical(root->right, subRoot->right)){ //agar right identical nahi hai toh false return kardo
                return false;
            } else { // agar dono identical hai toh true return kardo
                return true;
            }
    }
}

// Main function: root mein subRoot exist karta hai ya nahi
bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    // Agar root NULL hai toh false return karo
    if (root == NULL) return false;

    // Agar root aur subRoot ka structure match karta hai
    if (root->val == subRoot->val && isIdentical(root, subRoot)) {
        return true;
    }

    // Nahi toh left ya right subtree mein check karo
    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}

// Tree banane ke liye helper function
TreeNode* newNode(int val) {
    return new TreeNode(val);
}

// Sample test case
int main() {
    /*
        Main Tree:
                3
               / \
              4   5
             / \
            1   2

        Sub Tree:
              4
             / \
            1   2
    */

    TreeNode* root = newNode(3);
    root->left = newNode(4);
    root->right = newNode(5);
    root->left->left = newNode(1);
    root->left->right = newNode(2);

    TreeNode* subRoot = newNode(4);
    subRoot->left = newNode(1);
    subRoot->right = newNode(2);

    // Subtree check kiya
    if (isSubtree(root, subRoot)) {
        cout << "Yes, subRoot is a subtree of root." << endl;
    } else {
        cout << "No, subRoot is NOT a subtree of root." << endl;
    }

    return 0;
}

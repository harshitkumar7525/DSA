#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data) : val(data), left(nullptr), right(nullptr) {}
};
TreeNode* deleteNode(TreeNode* root, int key) {
    if (!root) // If the tree is empty, return null
        return NULL;
    if (root->val == key) // If the root is the node to be deleted
        return helper(root);
    TreeNode* ptr = root;
    while (ptr) {
        if (key < ptr->val) { // agar key current node ke value se chhota hai to left subtree mein jaate hain
            if (ptr->left && ptr->left->val == key) { // agar left child ka value key ke barabar hai to usko delete karte hain
                TreeNode* del = ptr->left;  // delete karne wale node ko store karte hain
                ptr->left = helper(ptr->left); // helper function se jis node ko delete karna hai uske child se connnect karte hain
                delete del; // delete karte hain node ko
                break;
            } else {
                ptr = ptr->left; // agar left child ka value key ke barabar nahi hai to current node ko left mein move karte hain
            }
        } else {
            if (ptr->right && ptr->right->val == key) { // agar key current node ke value se bada hai to right subtree mein jaate hain
                TreeNode* del = ptr->right; // delete karne wale node ko store karte hain
                ptr->right = helper(ptr->right);  // helper function se jis node ko delete karna hai uske child se connect karte hain
                delete del; // delete karte hain node ko
                break;
            } else {
                ptr = ptr->right; // agar right child ka value key ke barabar nahi hai to current node ko right mein move karte hain
            }
        }
    }
    return root;
}
TreeNode* helper(TreeNode* root) { // jis node ko delete karna hai uska helper function
    if (!root->left && !root->right){ // agar dono children null hain to null return karte hain
        return NULL;
    }
    else if (!root->left || !root->right){
        return root->right ? root->right : root->left; // agar sirf ek child hai to usi child ko return karte hain
    }
    TreeNode* rightChild = root->right; // jis node ko delete karna hai uska right child store karte hain
    TreeNode* leftRightMost = root->left; // left subtree ka rightmost node find karte hain
    while (leftRightMost->right) { // jab tak left subtree ka rightmost node nahi milta tab tak loop chalta hai
        leftRightMost = leftRightMost->right;
    }
    leftRightMost->right = rightChild; // left subtree ka rightmost node ka right child ko right child se connect karte hain
    return root->left; // return left subtree as the new root
}
int main() {
    /*
    Tree Structure:
            10
           /  \
          5    15
         / \     \
        3   7    18
    */
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);
    root->right->right = new TreeNode(18);

    int key = 7;
    root = deleteNode(root, key);
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        cout << node->val << " ";
        if (node->left)
            q.push(node->left);
        if (node->right)
            q.push(node->right);
    }

    return 0;
}
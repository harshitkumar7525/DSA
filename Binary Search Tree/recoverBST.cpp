#include <bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Test{
private:
    TreeNode *first; // First misplaced node
    TreeNode *second; // Second misplaced node
    TreeNode *prev; // Previous node in inorder traversal

public:
    void helper(TreeNode *curr){ // helper function inorder traversal ke liye
        if (!curr) // agar current node NULL hai to return karte hain
            return;
        helper(curr->left); // left subtree ko traverse karte hain
        if (prev != NULL && prev->val > curr->val){ // agar previous node ka value current node ke value se bada hai
            // iska matlab previous node misplaced hai
            if (!first){  // agar first node abhi set nahi hui hai aur prev value current se bada hai
                // iska matlab yehi hua ki hamse first misplaced node mil gayi hai
                first = prev;
                second = curr; // hm assume krte hain ki adjacent nodes misplaced hain
            } else { // hm log seconnd misplaced node search kar rahe hain
                // agar first null nahi hai iska matlab yeh hua ki hm logon ko second misplaced node mil gayi hai
                second = curr; // second node ko current node se set karte hain
            }
        }
        prev = curr; // next time ke liye previous node ko current node se set karte hain
        helper(curr->right); // right subtree ko traverse karte hain
    }
    void recoverTree(TreeNode *root){
        first = second = prev = NULL;
        helper(root);
        swap(first->val, second->val); // first aur second nodes ke values ko swap karte hain
    }
};
void printInorder(TreeNode *root){
    if (!root)
        return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}
int main(){
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(2);
    Test test; 
    cout << "Inorder before recovery: ";
    printInorder(root);
    cout << endl;
    test.recoverTree(root);
    cout << "Inorder after recovery: ";
    printInorder(root);
    return 0;
}
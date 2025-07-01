#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Helper{ // Binary Search Tree ke liye inorder aur reverse inorder traversal ka helper class
    // is class ka use inorder aur reverse inorder traversal ke liye kiya jaata hai
    private:
    stack<TreeNode*> s; // traversal ke liye stack ka use karte hain
    bool rev; // agar rev true hai to reverse inorder traversal hoga, warna inorder traversal hoga
    public:
    void pushAll(TreeNode* node){ // is function ka use stack mein nodes ko push karne ke liye kiya jaata hai
        // agar rev true hai to right subtree se start karte hain, warna left subtree se
        if(this->rev){
            while(node){
                s.push(node);
                node=node->right;
            }
        } else {
            while(node){
                s.push(node);
                node=node->left;
            }
        }
    }
    Helper(TreeNode* root,bool r){ // constructor jo root node aur rev flag ko initialize karta hai
        // agar rev true hai to reverse inorder traversal hoga, warna inorder traversal hoga
        this->rev=r;
        pushAll(root);
    }
    int next(){ // is function ka use next element ko retrieve karne ke liye kiya jaata hai
        TreeNode* curr = s.top(); // stack ke top se current node ko lete hain
        s.pop(); // stack se current node ko pop karte hain
        if(this->rev){ // agar rev true hai to reverse inorder traversal hoga
            if(curr->left){ // agar current node ka left child hai to usse stack mein push karte hain
                pushAll(curr->left);
            }
        } else { // agar rev false hai to inorder traversal hoga
            if(curr->right){ // agar current node ka right child hai to usse stack mein push karte hain
                pushAll(curr->right);
            }
        }
        return curr->val; // current node ka value return karte hain
    }
};
bool findTarget(TreeNode* root, int k) {
    Helper in(root,false); // seedha inorder traversal ke liye helper class ka object banate hain
    Helper revIn(root,true); // reverse inorder traversal ke liye helper class ka object banate hain
    int i = in.next(); // inorder traversal se pehla element lete hain (smallest element)
    int j=revIn.next(); // reverse inorder traversal se pehla element lete hain (largest element)
    while(i<j){ // jab tak inorder traversal ka element chhota hai reverse inorder traversal ke element se
        int sum = i+j;  // dono elements ka sum nikalte hain
        if(sum==k) return true; // agar sum k ke barabar hai to true return karte hain
        else if(sum<k) i=in.next(); // agr sum chhota hai then sum log toh next larger element lo inorder traversal se
        else j=revIn.next(); // agr sum bada hai then sum log toh next smaller element lo reverse inorder traversal se
    }
    return false; // agar koi pair nahi milta hai to false return karte hain
}
int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);
    int target = 9;
    if (findTarget(root, target)) {
        cout << "Target found!" << endl;
    } else {
        cout << "Target not found." << endl;
    }
    return 0;
}
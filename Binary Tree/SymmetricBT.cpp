#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};
bool helper(Node* left,Node* right){
    if(!left && !right) return true;
    else if(!left || !right) return false;
    else{
        if(left->data == right->data){
            return helper(left->left,right->right) && helper(left->right, right->left);
        } else {
            return false;
        }
    }
}
bool isSymmetric(Node* root) {
    if(!root->left && !root->right){
        return true;
    } else if (!root->left || !root->right){
        return false;
    } else {
        return helper(root->left,root->right);
    }
}
int main(){
    // Create a binary tree
    /*
            1
           / \
          2   2
         / \ / \
        3  4 4  3
    */
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(4);
    root->right->right = new Node(3);

    if(isSymmetric(root)){
        cout << "The tree is symmetric." << endl;
    } else {
        cout << "The tree is not symmetric." << endl;
    }
    
    return 0;
}
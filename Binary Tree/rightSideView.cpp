#include <bits/stdc++.h>
using namespace std;
struct TreeNode{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val), left(NULL), right(NULL) {}
};

vector<int> rightSideView(TreeNode *root){
    vector<int> ans;
    if (!root) return ans; // root null hua toh empty vector return kar do
    // level order traversal karte hain
    queue<TreeNode *> q; // queue mein TreeNode pointers store karenge
    q.push(root); // root ko queue mein daal do
    while (!q.empty()){ // jab tak queue khali nahi hoti
        int levelSize = q.size(); // current level ke nodes ki count
        TreeNode *curr = nullptr; // current node ko null se initialize karte hain
        for (int i = 0; i < levelSize; ++i){ // current level ke nodes ko process karte hain
            curr = q.front(); // queue se front node ko le lo
            q.pop(); // queue se front node ko hata do
            if (curr->left) // agar left child hai toh usko queue mein daal do
                q.push(curr->left);
            if (curr->right) // agar right child hai toh usko queue mein daal do
                q.push(curr->right);
        }
        // jab loop khatam hota hai toh curr mein current level ka last node hota hai
        // isliye usko answer mein daal do
        ans.push_back(curr->data);
    }
    return ans;
}

int main(){
    // Create a binary tree
    TreeNode* root = new TreeNode(1); // root node create kiya
    root->left=new TreeNode(2); // left child create kiya
    root->left->right=new TreeNode(5); // left child ka right child create kiya
    root->right=new TreeNode(3); // right child create kiya
    root->right->right=new TreeNode(4); // right child ka right child create kiya
    vector<int> view = rightSideView(root); // right side view ko get kiya
    for(auto i:view){
        cout<<i<<" ";
    }
    return 0;
}
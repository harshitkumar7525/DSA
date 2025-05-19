#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(NULL), right(NULL) {}
};
int widthOfBinaryTree(TreeNode* root) {
    if(!root) return 0;
    queue<pair<TreeNode*,unsigned long long>> q; // queue mein pair rakha hai jisme first element node hai aur second element uska index hai
    q.push({root,0}); // root ko queue mein daal rahe hain aur uska index 0 hai
    int ans=0;
    while(!q.empty()){ 
        int size = q.size();
        int levelmin=q.front().second; // levelmin current level ka minimum index hai
        // jiski help se hum next level ke index ko calculate kar sakte hain
        int first,last; // first aur last left most aur right most node ke index hain
        for(int i=0;i<size;i++){
            pair<TreeNode*,unsigned long long> curr = q.front(); // current node aur uska index
            q.pop();
            unsigned long long currIdx = curr.second-levelmin; // current index ko levelmin se minus kar rahe hain
            if(i==0) first = currIdx; // agar i 0 hai toh first ko current index se set kar rahe hain
            if(i==size-1) last = currIdx; // agar i size-1 hai toh last ko current index se set kar rahe hain
            if(curr.first->left) q.push({curr.first->left,2*currIdx+1}); // left child ka index 2*currentIndex+1 hota hai
            if(curr.first->right) q.push({curr.first->right,2*currIdx+2}); // right child ka index 2*currentIndex+2 hota hai
        }
        ans=max(ans,last-first+1);
    }
    return ans;
}
int main(){
    // Create a binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    cout << "Maximum width of the binary tree is: " << widthOfBinaryTree(root) << endl;
    return 0;
}
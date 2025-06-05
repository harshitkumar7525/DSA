#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode* helper(vector<int>& preorder, vector<int>& inorder,int &preIdx,int left,int right,unordered_map<int,int>& idx){
    if(left>right) return NULL; // Agar left index right se bada ho, toh iska matlab subtree khatam ho gaya hai
    TreeNode* root = new TreeNode(preorder[preIdx]); // Preorder mein current root node ko nikaalte hain
    preIdx++; // Preorder mein next element ke liye preIdx ko increment karte hain
    int inIdx=idx[root->val]; // Inorder mein current root node ki index nikaalte hain
    root->left=helper(preorder,inorder,preIdx,left,inIdx-1,idx); // Left subtree ke liye helper function call karte hain
    root->right=helper(preorder,inorder,preIdx,inIdx+1,right,idx); // Right subtree ke liye helper function call karte hain
    return root;
}
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int n=inorder.size();
    if(!n) return NULL;
    unordered_map<int,int> mp;
    /*
    map mein inorder ke elements aur unki index store karte hain
    taaki hum inorder mein kisi bhi element ki index O(1) mein nikaal sakein
    */
    for(int i=0;i<n;i++){
        mp[inorder[i]]=i;
    }
    int preIdx=0; // preIdx ko 0 se initialize karte hain, kyunki preorder mein hum root se start karte hain
    return helper(preorder,inorder,preIdx,0,n-1,mp);
}
int main() {
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};
    TreeNode* root = buildTree(preorder, inorder);
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        if(node) {
            cout << node->val << " ";
            q.push(node->left);
            q.push(node->right);
        } else {
            cout << "null ";
        }
    }
    return 0;
}

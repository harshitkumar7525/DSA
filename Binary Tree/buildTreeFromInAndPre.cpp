#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : val(val), left(NULL), right(NULL) {}
};
// inorder mein kisi value ka index dhoondhne ke liye function
// yeh function left se right tak search karta hai aur index return karta hai
int search( vector<int>& inorder,int left,int right,int val){
    for(int i=left;i<=right;i++){ 
        if(inorder[i]==val) return i;
    }
    return -1;
}
// helper function jo preorder aur inorder traversal se tree banata hai
TreeNode* helper(vector<int>& preorder, vector<int>& inorder,int &preIdx,int left, int right){ 
    // base case hai jab left index right se bada ho jaye, toh NULL return karo
    // yeh condition tab hoti hai jab humne saare nodes process kar liye hain
    if(left>right){  
        return NULL;
    }
    // preorder mein hamesha starting node root hoti hai, toh usko le lo
    // aur preIdx ko increment karo kyunki humne ek node process kar liya hai
    TreeNode* root = new TreeNode(preorder[preIdx]);
    preIdx++;
    // ab hm iss node ki value ki inorder mein index dhoondhne wale hain
    int inIdx=search(inorder,left,right,root->val);
    // iss index se hm apne subtree ko do parts mein baat sakte hain
    // left subtree ke liye left se inIdx-1 tak aur right subtree ke liye inIdx+1 se right tak
    // recurisively left aur right subtree ko process karte hain
    // yeh dono calls left aur right construct karne ke liye hain
    root->left=helper(preorder,inorder,preIdx,left,inIdx-1);
    root->right=helper(preorder,inorder,preIdx,inIdx+1,right);
    // finally root node ko return karte hain
    // yeh root node ab left aur right subtree ke saath connected hai 
    return root;
}
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    // preIdx ko 0 se initialize karte hain kyunki hum preorder traversal se start kar rahe hain
    int preIdx=0;
    // helper function ko call karte hain jo tree banata hai
    // yeh function preorder aur inorder traversal ko use karke tree banata hai
    TreeNode* root = helper(preorder,inorder,preIdx,0,inorder.size()-1);
    return root;
}
void levelOrder(TreeNode* root){
    if(root==NULL) return;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode* curr=q.front();
        q.pop();
        cout<<curr->val<<" ";
        if(curr->left) q.push(curr->left);
        if(curr->right) q.push(curr->right);
    }
}
int main(){
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};
    TreeNode* root = buildTree(preorder, inorder);
    cout << "Level Order Traversal of the constructed tree: ";
    levelOrder(root);
    return 0;
}
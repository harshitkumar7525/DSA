/*
 Iterative traversals of binary tree
*/

#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(NULL), right(NULL) {}
};
vector<int> preOrder(TreeNode* root){
    vector<int> ans;
    if(!root) return ans; // agar root null hai toh kuch nahi karna
    stack<TreeNode*> s; 
    s.push(root); // stack mein root ko daal rahe hain
    // jab tak stack khali nahi hota tab tak chalte rahenge
    while(!s.empty()){
        TreeNode* node = s.top(); // stack ka top element le rahe hain
        s.pop();
        ans.push_back(node->val); // is node ka value ans mein daal rahe hain
        // pehle right child ko stack mein daal rahe hain kyuki jab hum left child ko visit karte hain toh right child pehle aata hai
        // toh right child ko pehle stack mein daal rahe hain
        if(node->right) s.push(node->right);
        // ab left child ko stack mein daal rahe hain
        // kyuki left child ko pehle visit karna hai
        if(node->left) s.push(node->left);
    }
    return ans;
}
vector<int> postOrder(TreeNode* root){
    vector<int> ans;
    if(!root) return ans;
    stack<pair<TreeNode*,bool>> s; 
    // stack mein hm pair rakh rahe hain jismein pehla element node hai aur
    // dusra element bool hai jo yeh batata hai ki kya humne is node ko visit kiya hai ya nahi
    // jab hum node ko visit karte hain toh hum isko true karte hain
    s.push({root,false}); // stack mein root ko false ke sath daal rahe hain kyuki humne isko abhi tak visit nahi kiya hai
    // jab hum node ko visit karte hain toh hum isko true karte hain
    while(!s.empty()){
        auto temp = s.top(); // stack ka top element le rahe hain
        s.pop(); 
        TreeNode* curr = temp.first; 
        bool v = temp.second;
        if(curr){  // agar current node null nahi hai toh
            if(v){ // agar humne is node ko visit kiya hai toh
                ans.push_back(curr->val); // is node ka value ans mein daal rahe hain
            }
            else { // agar humne is node ko visit nahi kiya hai toh
                s.push({curr,true}); // to hm iss node ko visited mark krke stack mein wapas daal rahe hain
                s.push({curr->right,false}); // right child ko stack mein daal rahe hain
                s.push({curr->left,false}); // left child
            }
        }
    }
    return ans;
}
vector<int> inOrder(TreeNode* root){
    vector<int> ans;
    if(!root) return ans;
    stack<TreeNode*> s;
    TreeNode* node = root;
    while (true) {
        if (node != NULL) { // agar current node null nahi hai toh
            s.push(node);
            node = node->left; // left child ko stack mein daal rahe hain
        } else {  // agar current node null hai toh
            if (s.empty()) { // agar stack khali hai toh
                break; // toh loop se bahar aa jao
            }
            node = s.top(); // stack ka top element le rahe hain
            s.pop();
            ans.push_back(node->val); // is node ka value ans mein daal rahe hain
            node = node->right; // right child ko stack mein daal rahe hain
        }
    }
    return ans;
}
int main(){
    // Create a binary tree
    /*
            1
           / \
          2   7
         / \
        3   4
           / \
          5   6
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->left->right->right = new TreeNode(6);
    root->left->right->left = new TreeNode(5);
    vector<int> ans = postOrder(root);
    for(auto i:ans){
        cout<<i<<" ";
    }
    return 0;
}
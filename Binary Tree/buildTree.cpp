#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode* helperInAndPre(vector<int>& preorder, vector<int>& inorder,int &preIdx,int left,int right,unordered_map<int,int>& idx){
    if(left>right) return NULL; // Agar left index right se bada ho, toh iska matlab subtree khatam ho gaya hai
    TreeNode* root = new TreeNode(preorder[preIdx]); // Preorder mein current root node ko nikaalte hain
    preIdx++; // Preorder mein next element ke liye preIdx ko increment karte hain
    int inIdx=idx[root->val]; // Inorder mein current root node ki index nikaalte hain
    root->left=helperInAndPre(preorder,inorder,preIdx,left,inIdx-1,idx); // Left subtree ke liye helper function call karte hain
    root->right=helperInAndPre(preorder,inorder,preIdx,inIdx+1,right,idx); // Right subtree ke liye helper function call karte hain
    return root;
}
TreeNode* buildTreeInAndPre(vector<int>& preorder, vector<int>& inorder) {
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
    return helperInAndPre(preorder,inorder,preIdx,0,n-1,mp);
}
TreeNode* helperInAndPost(vector<int>& inorder, vector<int>& postorder,int left,int right,int &pIdx,unordered_map<int,int> &idx){
        if(left>right) return NULL; // Agar left index right se bada ho, toh iska matlab subtree khatam ho gaya hai
        TreeNode* curr = new TreeNode(postorder[pIdx]); // Postorder mein current root node ko nikaalte hain
        pIdx--; // Postorder mein next element ke liye pIdx ko decrement karte hain
        int iDx=idx[curr->val]; // Inorder mein current root node ki index nikaalte hain
        curr->right=helperInAndPost(inorder,postorder,iDx+1,right,pIdx,idx); // Right subtree ke liye helper function call karte hain
        curr->left=helperInAndPost(inorder,postorder,left,iDx-1,pIdx,idx); // Left subtree ke liye helper function call karte hain
        return curr;
    }
    TreeNode* buildTreeInAndPost(vector<int>& inorder, vector<int>& postorder) {
        int n=postorder.size();
        unordered_map<int,int> mp; // Map mein inorder ke elements aur unki index store karte hain
        for(int i=0;i<n;i++){
            mp[inorder[i]]=i;
        }
        int postIdx=n-1; // postIdx ko n-1 se initialize karte hain, kyunki postorder mein hum last element se start karte hain
        return helperInAndPost(inorder,postorder,0,n-1,postIdx,mp); 
    }
int main() {
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};
    TreeNode* root1 = buildTreeInAndPre(preorder, inorder);
    TreeNode* root2 = buildTreeInAndPost(inorder, postorder);
    // level order traversal to verify the tree structure
    queue<TreeNode*> q;
    q.push(root1);
    cout << "Level order traversal of tree built from Inorder and Preorder:" << endl;
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        if (node) {
            cout << node->val << " ";
            q.push(node->left);
            q.push(node->right);
        } else {
            cout << "null ";
        }
    }
    cout << endl;
    q.push(root2);
    cout << "Level order traversal of tree built from Inorder and Postorder:" << endl;
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        if (node) {
            cout << node->val << " ";
            q.push(node->left);
            q.push(node->right);
        } else {
            cout << "null ";
        }
    }
    return 0;
}

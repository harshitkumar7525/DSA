#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(NULL), right(NULL) {}
};

int topDownSum(TreeNode* root, int &maxi){
    if(!root) return 0;  // agar root null hai toh 0 return karo
    // hm log partial(one side) path sum nikal rahe hai
    int ls = max(topDownSum(root->left,maxi),0); // left subtree se maximum sum
    int rs = max(topDownSum(root->right,maxi),0); // right subtree se maximum sum
    maxi=max(maxi,ls+rs+root->val); // update the maximum path sum
    return root->val+max(ls,rs); // hmlog abhi tk jo bhi path sum nikal paye hai usko return karenge
}
int maxPathSum(TreeNode* root) {
    int maxi = INT_MIN; // Initialize maximum to minimum integer value
    topDownSum(root,maxi); // Call the helper function to calculate maximum path sum
    return maxi; 
}
int main(){
    // Create a binary tree
    /*
            -10
           /  \
          9   20
              /  \
             15   7
    */
    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    cout << "Maximum Path Sum: " << maxPathSum(root) << endl;
    return 0;
}
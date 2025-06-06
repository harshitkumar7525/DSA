#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
vector<int> inOrder(TreeNode* root) {
    vector<int> result;  // vector mein inorder traversal ke elements store karne ke liye
    TreeNode* current = root; // current pointer ko root se initialize karte hain
    while (current) { // jab tak current pointer NULL nahi ho jata
        if (!current->left) { // Agar current node ka left child NULL hai
            result.push_back(current->val); // current node ka value result mein daal dete hain
            current = current->right; // aur current pointer ko right child ki taraf move karte hain
        } else { // Agar current node ka left child NULL nahi hai
            TreeNode* pre = current->left; // pre pointer ko current node ke left child se initialize karte hain
            while (pre->right && pre->right != current) { // pre pointer ko current node ke left subtree mein rightmost node tak le jaate hain
                // jab tak right child null nahi hai aur pre ka right child current node nahi hai
                // isse hum current node ke left subtree mein rightmost node tak pahunch jaate hain
                pre = pre->right;
            }
            if (!pre->right) { // Agar pre ka right child NULL hai
                pre->right = current; // temporary link create karte hain current node ke saat
                current = current->left; // aur current pointer ko left child ki taraf move karte hain
            } else { // Agar pre ka right child current node hai
                // temporary link already exist karta hai, iska matlab hum current node ke left subtree se waapas aa gaye hain
                pre->right = NULL; // temporary link ko remove karte hain
                result.push_back(current->val); // current node ka value result mein daal dete hain
                current = current->right; // aur current pointer ko right child ki taraf move karte hain
            }
        }
    }
    return result;
}
vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result; // vector mein preorder traversal ke elements store karne ke liye
        TreeNode* current = root; // current pointer ko root se initialize karte hain
        while (current) { // jab tak current pointer NULL nahi ho jata
            if (!current->left) { // Agar current node ka left child NULL hai
                result.push_back(current->val); // current node ka value result mein daal dete hain
                current = current->right; // aur current pointer ko right child ki taraf move karte hain
            } else { // Agar current node ka left child NULL nahi hai
                TreeNode* pre = current->left; // pre pointer ko current node ke left child se initialize karte hain
                while (pre->right && pre->right != current) { // pre pointer ko current node ke left subtree mein rightmost node tak le jaate hain
                // jab tak right child null nahi hai aur pre ka right child current node nahi hai
                    pre = pre->right;
                }
                if (!pre->right) { // Agar pre ka right child NULL hai
                    pre->right = current; // temporary link create karte hain current node ke saath
                    result.push_back(current->val); // current node ka value result mein daal dete hain
                    current = current->left; // aur current pointer ko left child ki taraf move karte hain
                } else { // Agar pre ka right child current node hai
                    // temporary link already exist karta hai, iska matlab hum current node ke left subtree se waapas aa gaye hain
                    pre->right = NULL; // temporary link ko remove karte hain
                    current = current->right; // aur current pointer ko right child ki taraf move karte hain
                }
            }
        }
        return result;
    }
int main(){
    /*
    Tree structure:
            1
           / \
          2   3
         / \   \
        4   5   6
         \     / \
          7   8   9
    */
    TreeNode* root = new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->left->left->right=new TreeNode(7);
    root->left->right=new TreeNode(5);
    root->right->left=new TreeNode(6);
    root->right->left->left=new TreeNode(8);
    root->right->left->right=new TreeNode(9);
    vector<int> result = inOrder(root);
    cout << "Inorder Traversal using Morris Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    vector<int> preResult = preorderTraversal(root);
    cout << "Preorder Traversal using Morris Traversal: ";
    for (int val : preResult) {
        cout << val << " ";
    }
    return 0;
}
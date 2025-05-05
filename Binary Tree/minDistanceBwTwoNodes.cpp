#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};
// Lowest Common Ancestor find karne ke liye function
Node *findLca(Node *root, int a, int b){
    if (!root)
        return NULL; // agar root NULL hai toh kuch bhi return nahi kar sakte
    if (root->data == a || root->data == b)
        return root; // agar a ya b mil gaya toh wahi LCA ho sakta hai

    Node *left = findLca(root->left, a, b);   // left subtree mein LCA dhoondho
    Node *right = findLca(root->right, a, b); // right subtree mein LCA dhoondho

    // agar a aur b dono alag-alag side mein mile, toh current node hi LCA hai
    if (left && right)
        return root;

    // agar sirf ek side mein mila, toh wahi LCA hoga
    return left ? left : right;
}

// kisi node se ek particular value tak ka distance nikalne ka function
int helper(Node *root, int n){
    if (!root)
        return -1; // agar NULL hai toh -1 return karo (not found)
    if (root->data == n)
        return 0; // agar value mil gayi toh distance 0 hai

    int left = helper(root->left, n);   // left side mein distance check karo
    int right = helper(root->right, n); // right side mein bhi check karo

    // agar left mein mil gaya toh left+1, warna right mein mil gaya toh right+1
    // dono mein nahi mila toh -1
    return left != -1 ? left + 1 : (right != -1 ? right + 1 : -1);
}

// do nodes ke beech ka distance nikalne ke liye main function
int findDist(Node *root, int a, int b){
    Node *lca = findLca(root, a, b); // pehle LCA find karo
    int d1 = helper(lca, a);         // LCA se a tak ka distance
    int d2 = helper(lca, b);         // LCA se b tak ka distance
    return d1 + d2;                  // total distance = d1 + d2
}
int main(){
    // Create a binary tree
    /*
    Tree structure:
            11
           /  \
         22    33
        / \    / \
      44   55 66  77
    */
    Node *root = new Node(11);
    root->left = new Node(22);
    root->right = new Node(33);
    root->left->left = new Node(44);
    root->left->right = new Node(55);
    root->right->left = new Node(66);
    root->right->right = new Node(77);
    cout << "The distance between 77 and 22 is: ";
    cout << findDist(root, 77, 22) << endl;
    return 0;
}
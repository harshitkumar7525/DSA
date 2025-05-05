#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};
Node* generateTreeByLevelOrder(vector<int> arr) {
    if (arr.empty()) return NULL;
    Node* root = new Node(arr[0]);
    queue<Node*> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < arr.size()) {
        Node* current = q.front();
        q.pop();
        if (arr[i] != -1) {
            current->left = new Node(arr[i]);
            q.push(current->left);
        }
        i++;
        if (i >= arr.size()) break;
        if (arr[i] != -1) {
            current->right = new Node(arr[i]);
            q.push(current->right);
        }
        i++;
    }
    return root;
}
Node* lowestCommonAncestor(Node* root, int p, int q) {
    if(!root) return NULL; // agar root NULL hai toh kuch nahi karna
    if(root->data==p || root->data == q) return root; // agar current node p ya q hai toh yeh node return karo
    Node* left = lowestCommonAncestor(root->left,p,q); // left subtree se check karo
    Node* right = lowestCommonAncestor(root->right,p,q); // right subtree se check karo
    if( left && right ) return root; // agar dono left aur right se kuch mila toh yeh root hai LCA
    else return left ? left : right; // agar sirf left ya right se kuch mila toh wahi return karo
}
int main(){
    // Create a binary tree
    /*
    Tree structure:
            3
          /   \
         5     1
        / \   / \
       6   2 0   8
          / \
         7   4
    */
    vector<int> arr = {3,5,1,6,2,0,8,-1,-1,7,4,-1,-1,-1,-1,-1};
    Node* root = generateTreeByLevelOrder(arr);
    int v1 = 6;
    int v2 = 4;
    Node* lca = lowestCommonAncestor(root, v1, v2); // lowest common ancestor ko find karo
    if (lca != NULL) {
        cout << "Lowest Common Ancestor of " << v1 << " and " << v2 << " is: " << lca->data << endl;
    } else {
        cout << "Lowest Common Ancestor not found." << endl;
    }
    return 0;
}
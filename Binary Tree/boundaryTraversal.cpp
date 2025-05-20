#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};
bool isLeaf(Node* node){
    if(!node->left && !node->right) return true; // agar node ka koi child nahi to woh leaf hai
    else return false;
}
void addLeft(Node* root,vector<int> &ans){
    Node* curr = root->left; // left child se start karte hai
    while(curr){ 
        if(!isLeaf(curr)) ans.push_back(curr->data); // agar leaf nahi hai toh uski value add karo
        if(curr->left) curr=curr->left; // left child ki taraf jao
        else curr=curr->right; // agar left nahi hai toh right child ki taraf jao
    }
}
void addRight(Node* root,vector<int> &ans){ 
    Node* curr = root->right; // right child se start karte hai
    vector<int> temp; // right boundary ko store karne ke liye
    while(curr){
        if(!isLeaf(curr)) temp.push_back(curr->data); // agar leaf nahi hai toh uski value add karo
        if(curr->right) curr=curr->right; // right child ki taraf jao
        else curr=curr->left; // agar right nahi hai toh left child ki taraf jao
    }
    reverse(temp.begin(),temp.end()); // right boundary ko reverse karna hai kyunki humein bottom se top ki taraf chahiye
    ans.insert(ans.end(),temp.begin(),temp.end()); // temp vector ko ans me daal do
}
void addLeaf(Node* root,vector<int>& ans){
    if(isLeaf(root)){ // agar leaf hai toh uski value add karo
        ans.push_back(root->data); 
        return;
    }
    if(root->left) addLeaf(root->left,ans); // left child ko check karo
    if(root->right) addLeaf(root->right,ans); // right child ko check karo
}
vector<int> boundaryTraversal(Node *root) {
    vector<int> ans; // traversal ka answer store karne ke liye
    if(!root) return ans; // agar root null hai toh kuch nahi karna
    if(!isLeaf(root)) ans.push_back(root->data); // agar root leaf nahi hai toh uski value add karo
    addLeft(root,ans); // left boundary ko add karo
    addLeaf(root,ans); // leaf nodes ko add karo
    addRight(root,ans); // right boundary ko add karo lekin reverse order me
    return ans; // final answer return karo
}
int main(){
    // Create a binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // Get the boundary traversal
    vector<int> boundary = boundaryTraversal(root);

    // Print the boundary traversal
    for(int val : boundary) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
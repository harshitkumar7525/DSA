#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};
vector<vector<int>> zigzagLevelOrder(Node* root) {
    vector<vector<int>> ans;
    if (!root) return ans; // agar root null hai toh kuch nahi karna
    queue<Node*> q; 
    q.push(root); // queue mein root ko daal rahe hain
    bool rev = false; // flag to reverse the order
    while (!q.empty()) { // jab tak queue khali nahi hota tab tak chalte rahenge
        int size = q.size(); // current level ka size le rahe hain
        vector<int> level; // current level ke elements ko store karne ke liye vector
        for (int i = 0; i < size; i++) { // normal level order traversal
            Node* curr = q.front();
            q.pop();
            level.push_back(curr->data);
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
        if(rev){ // agar rev true hai toh level ko reverse karna hai
            reverse(level.begin(),level.end());
        }
        ans.push_back(level);
        rev=!rev;
    }
    return ans;
}
int main(){
    // Create a binary tree
    /*
            1
           / \
          2   3
         / \ / \
        4  5 6  7
    */
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    vector<vector<int>> ans = zigzagLevelOrder(root);
    for(auto i:ans){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}
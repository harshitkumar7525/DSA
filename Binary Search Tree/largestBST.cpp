#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};
class Test {
private:
    int ans = 0;
public:
    tuple<bool,int,int,int> helper(Node* node){
        if (!node) { 
            return make_tuple(true,0,INT_MAX,INT_MIN); // agar node null hai to return true, size 0, min INT_MAX, max INT_MIN
        }
        auto left = helper(node->left);
        bool leftIsBST = get<0>(left); // left subtree BST hai ya nahi
        int leftSize = get<1>(left); // left subtree ka size
        int leftMin = get<2>(left); // left subtree ka minimum value
        int leftMax = get<3>(left); // left subtree ka maximum value
        
        auto right = helper(node->right);
        bool rightIsBST = get<0>(right); // right subtree BST hai ya nahi
        int rightSize = get<1>(right); // right subtree ka size
        int rightMin = get<2>(right); // right subtree ka minimum value
        int rightMax = get<3>(right); // right subtree ka maximum value

        if(leftIsBST && rightIsBST && leftMax < node->data && node->data < rightMin){
            /*
            agar left subtree BST hai aur right subtree BST hai aur
            left subtree ka maximum value current node se chhota hai
            aur current node ka value right subtree ke minimum se chhota hai,
            to current node bhi BST ka part hai.
            */
            int size = 1 + leftSize + rightSize;  // current node ka size 1 hai plus left aur right subtree ka size
            int maximum = max(node->data,rightMax); // current node ka maximum value
            int minimum = min(node->data,leftMin); // current node ka minimum value
            ans=max(ans,size); // ans ko update karte hain agar current size zyada hai
            return make_tuple(true,size,minimum,maximum);
        } else {
            return make_tuple(false,0,INT_MAX,INT_MIN); // agar current node BST ka part nahi hai to return false, size 0, min INT_MAX, max INT_MIN
        }
        
    }
    int largestBst(Node *root) {
        helper(root);
        return ans;
    }
};
int main() {
    /*
    Tree structure:
            10
           /  \
          5    15
         / \     \
        1   8    20
    */
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->right->right = new Node(20);
    root->left->left = new Node(1);
    root->left->right = new Node(8);

    Test test;
    cout << "Size of the largest BST is: " << test.largestBst(root) << endl;

    return 0;
}
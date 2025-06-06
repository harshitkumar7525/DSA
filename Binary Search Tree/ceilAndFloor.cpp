#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};
Node* insert(Node* root, int val) {
    if (!root) return new Node(val);
    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}
vector<int> ceilAndFloor(Node* root, int key) {
    int ceil=-1;
    int floor=-1;
    while (root) {
        if (root->data == key) {
            return {key, key}; // agar root ka data key ke barabar hai to ceil aur floor dono wahi hain
        }
        if (root->data < key) { // agar root ka data key se chhota hai to ceil usi se aage hoga
            floor = root->data; // aur hum right subtree mein check karte hain
            root = root->right;
        } else {
            ceil = root->data; // agar root ka data key se bada hai to ceil wahi ho sakta hai
            root = root->left; // aur hum left subtree mein check karte hain
        }
    }
    return {floor, ceil}; // agar root null ho gaya to floor aur ceil return karte hain
}
int main(){
    Node* root = nullptr;
    vector<int> values = {15, 10, 20, 8, 12, 17, 25};
    for (int val : values) {
        root = insert(root, val);
    }
    int key = 14;
    vector<int> result = ceilAndFloor(root, key);
    cout << "Ceil: " << result[1] << ", Floor: " << result[0] << endl;
    return 0;
}
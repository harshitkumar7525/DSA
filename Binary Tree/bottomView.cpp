#include <bits/stdc++.h>
using namespace std;

// Node class banaya jo binary tree ka ek node represent karega
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Bottom view nikalne wali function
vector<int> bottomView(Node* root) {
    vector<int> ans;

    // Agar root null hai toh empty list return karo
    if (root == NULL) {
        return ans;
    }

    // HashMap mein horizontal distance aur node value ka pair store hoga
    unordered_map<int, int> mp;

    // Queue banayi for level order traversal (BFS)
    queue<pair<Node*, int>> q;
    q.push({root, 0}); // root ka hd 0 se start karte hain

    int minHd = 0, maxHd = 0; // horizontal distance ke min aur max values

    // BFS start
    while (!q.empty()) {
        Node* curr = q.front().first;
        int hd = q.front().second;
        q.pop();

        // Agar is hd pe pehli baar node aa rahi hai, toh hi usko map me daalo

            mp[hd] = curr->data;

        // Left child ko queue me daalo with hd - 1
        if (curr->left) {
            q.push({curr->left, hd - 1});
            minHd = min(minHd, hd - 1);
        }

        // Right child ko queue me daalo with hd + 1
        if (curr->right) {
            q.push({curr->right, hd + 1});
            maxHd = max(maxHd, hd + 1);
        }
    }

    // Final result nikalne ke liye map ke values ko vector me daal do
    for (int i = minHd; i <= maxHd; ++i) {
        ans.push_back(mp[i]);
    }

    return ans;
}

// Main function
int main() {
    /*
        Binary tree create kiya:
               1
              / \
             2   3
              \
               4
                \
                 5
                  \
                   6
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->right = new Node(4);
    root->left->right->right = new Node(5);
    root->left->right->right->right = new Node(6);
    root->right = new Node(3);

    // Bottom view call kiya
    vector<int> result = bottomView(root);

    // Output print kiya
    cout << "Bottom View: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}

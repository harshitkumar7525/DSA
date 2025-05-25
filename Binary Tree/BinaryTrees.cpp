#include <bits/stdc++.h>
using namespace std;

// Node structure banaya gya hai
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data; // node ke andar data assign kiya
        this->left = nullptr; // left pointer null se initialize
        this->right = nullptr; // right pointer null se initialize
    }
};

int idx = -1; // Global index to keep track of position in input array

// Tree build karne ka function - Preorder input ke basis par
Node* buildTree(vector<int>& nodes) {
    idx++; // index badhaya har call ke saath
    if (nodes[idx] == -1) return nullptr; // agar -1 mila to null return karo

    Node* newNode = new Node(nodes[idx]); // naye node banaya
    newNode->left = buildTree(nodes); // left subtree banaya
    newNode->right = buildTree(nodes); // right subtree banaya
    return newNode; // root return
}

// DFS - Preorder Traversal (Root -> Left -> Right)
void preOrder(Node* root) {
    if (root == nullptr) return; // base case
    cout << root->data << " "; // root pehle print karo
    preOrder(root->left); // left child
    preOrder(root->right); // right child
}

// DFS - Inorder Traversal (Left -> Root -> Right)
void inOrder(Node* root) {
    if (root == nullptr) return;
    inOrder(root->left); // left subtree
    cout << root->data << " "; // root print
    inOrder(root->right); // right subtree
}

// DFS - Postorder Traversal (Left -> Right -> Root)
void postOrder(Node* root) {
    if (root == nullptr) return;
    postOrder(root->left); // left
    postOrder(root->right); // right
    cout << root->data << " "; // root baad mein print
}

// BFS - Level Order Traversal
void levelOrder(Node* root) {
    if (root == nullptr) return;
    queue<Node*> q; // queue banaya BFS ke liye
    q.push(root); // root node push kiya
    q.push(nullptr); // Level separator

    while (!q.empty()) {
        Node* temp = q.front(); // front node nikala
        q.pop();

        if (temp == nullptr) {
            cout << endl; // Level complete
            if (!q.empty()) q.push(nullptr); // next level ke liye null
        } else {
            cout << temp->data << " "; // node print
            if (temp->left) q.push(temp->left); // left child push
            if (temp->right) q.push(temp->right); // right child push
        }
    }
}

// Total nodes count karna hai
int countNodes(Node* root) {
    if (root == nullptr) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right); // root + left subtree + right subtree
}

// Nodes ka sum nikalna hai
int sumOfNodes(Node* root) {
    if (root == nullptr) return 0;
    return root->data + sumOfNodes(root->left) + sumOfNodes(root->right); // root ka data + left + right
}

// Tree ki height nikalna (Node based - root count hota hai)
int heightOfTreeViaNode(Node* root) {
    if (root == nullptr) return 0;
    return max(heightOfTreeViaNode(root->left), heightOfTreeViaNode(root->right)) + 1; // max height of subtrees + 1
}

// Tree ki height (Edge based - edge count hota hai)
int heightOfTreeViaEdge(Node* root) {
    if (root == nullptr) return -1;
    return max(heightOfTreeViaEdge(root->left), heightOfTreeViaEdge(root->right)) + 1; // max height + 1
}

// Diameter via node count (slow approach)
int diameterViaNode(Node* root) {
    if (root == nullptr) return 0;

    int leftDiameter = diameterViaNode(root->left); // left subtree ka diameter
    int rightDiameter = diameterViaNode(root->right); // right subtree ka diameter
    int leftHeight = heightOfTreeViaNode(root->left); // left height
    int rightHeight = heightOfTreeViaNode(root->right); // right height

    int selfDiameter = leftHeight + rightHeight + 1; // self diameter
    return max({selfDiameter, leftDiameter, rightDiameter}); // max return karo
}

// Diameter via node (optimized approach)
pair<int, int> diameterHelperViaNode(Node* root) {
    if (root == nullptr) return {0, 0};

    auto left = diameterHelperViaNode(root->left); // left se height, diameter
    auto right = diameterHelperViaNode(root->right); // right se height, diameter

    int selfHeight = max(left.first, right.first) + 1; // height
    int selfDiameter = left.first + right.first + 1; // self diameter
    int maxDiameter = max({selfDiameter, left.second, right.second}); // max of all

    return {selfHeight, maxDiameter}; // return pair(height, diameter)
}

int diameterOptimizedViaNode(Node* root) {
    return diameterHelperViaNode(root).second; // optimized diameter
}

// Diameter via edge count (slow approach)
int diameterViaEdge(Node* root) {
    if (root == nullptr) return 0;

    int leftDiameter = diameterViaEdge(root->left); // left
    int rightDiameter = diameterViaEdge(root->right); // right
    int leftHeight = heightOfTreeViaEdge(root->left); // left height
    int rightHeight = heightOfTreeViaEdge(root->right); // right height

    int selfDiameter = leftHeight + rightHeight + 2; // self diameter
    return max({selfDiameter, leftDiameter, rightDiameter});
}

// Diameter via edge (optimized approach)
pair<int, int> diameterHelperViaEdge(Node* root) {
    if (root == nullptr) return {-1, 0}; // height = -1 (edge based)

    auto left = diameterHelperViaEdge(root->left); // left
    auto right = diameterHelperViaEdge(root->right); // right

    int selfHeight = max(left.first, right.first) + 1; // height
    int selfDiameter = left.first + right.first + 2; // edge-based diameter
    int maxDiameter = max({selfDiameter, left.second, right.second});

    return {selfHeight, maxDiameter};
}

int diameterOptimizedViaEdge(Node* root) {
    return diameterHelperViaEdge(root).second; // final optimized diameter
}

int main() {
    // Tree input diya gaya hai (Preorder with -1 as null)
    vector<int> nodes = {1,2,4,8,-1,-1,-1,5,-1,6,-1,7,-1,-1,3,-1,-1};

    Node* root = buildTree(nodes); // Tree build kiya

    cout << "Preorder: ";
    preOrder(root); // Root -> Left -> Right
    cout << endl;

    cout << "Inorder: ";
    inOrder(root); // Left -> Root -> Right
    cout << endl;

    cout << "Postorder: ";
    postOrder(root); // Left -> Right -> Root
    cout << endl;

    cout << "Level order: \n";
    levelOrder(root); // BFS traversal

    // Tree related info print kiya gaya hai
    cout << "\nThe number of nodes in this tree is: " << countNodes(root) << endl;
    cout << "The sum of all the nodes is: " << sumOfNodes(root) << endl;
    cout << "The height of tree via Node: " << heightOfTreeViaNode(root) << endl;
    cout << "The height of tree via Edge: " << heightOfTreeViaEdge(root) << endl;
    cout << "The diameter of the tree via Node is: " << diameterViaNode(root) << endl;
    cout << "The diameter (optimized) via Node is: " << diameterOptimizedViaNode(root) << endl;
    cout << "The diameter of the tree via Edge is: " << diameterViaEdge(root) << endl;
    cout << "The diameter (optimized) via Edge is: " << diameterOptimizedViaEdge(root) << endl;

    return 0;
}

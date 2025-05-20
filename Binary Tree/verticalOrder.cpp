#include <bits/stdc++.h>
using namespace std;

// Binary Tree ka basic structure
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(NULL), right(NULL) {}
};

// Vertical Traversal function
vector<vector<int>> verticalTraversal(TreeNode* root) {
    vector<vector<int>> ans;
    if (!root) return ans;

    // Queue banai BFS ke liye, jisme node ke saath vertical aur level bhi store hoga
    queue<pair<TreeNode*, pair<int, int>>> todo;

    // Map: vertical -> level -> multiset (multiple sorted nodes at same level)
    map<int, map<int, multiset<int>>> nodes;

    // Root node ko (0,0) coordinate par maana hai (vertical = 0, level = 0)
    todo.push({root, {0, 0}});

    // BFS traversal
    while (!todo.empty()) {
        auto ele = todo.front();
        todo.pop();

        TreeNode* curr = ele.first;
        int vertical = ele.second.first;
        int level = ele.second.second;

        // Current node ki value ko uske vertical aur level ke hisaab se map me daal diya
        nodes[vertical][level].insert(curr->val);

        // Left child ka vertical -1 aur level +1 hoga
        if (curr->left) todo.push({curr->left, {vertical - 1, level + 1}});

        // Right child ka vertical +1 aur level +1 hoga
        if (curr->right) todo.push({curr->right, {vertical + 1, level + 1}});
    }

    // Final answer banane ke liye map ko traverse kara
    for (auto v : nodes) {
        vector<int> col;
        for (auto l : v.second) {
            // multiset ke sorted elements ko col vector me daal diya
            col.insert(col.end(), l.second.begin(), l.second.end());
        }
        // Har vertical column ko final answer me daal diya
        ans.push_back(col);
    }

    return ans;
}

// Helper function to print 2D vector
void print2DVector(const vector<vector<int>>& vec) {
    for (const auto& row : vec) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    /*
        Sample tree:
                3
               / \
              9   20
                 /  \
                15   7

        Expected Vertical Order Traversal:
        [
          [9],
          [3, 15],
          [20],
          [7]
        ]
    */

    // Tree banaya
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    // Vertical traversal call kara
    vector<vector<int>> result = verticalTraversal(root);

    // Output print kara
    print2DVector(result);

    return 0;
}

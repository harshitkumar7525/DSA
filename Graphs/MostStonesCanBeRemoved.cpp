#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
public:
    vector<int> size, parent;

    DisjointSet(int n) {
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findParent(int u) {
        if (u == parent[u])
            return u;
        return parent[u] = findParent(parent[u]);
    }

    void unionBySize(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);
        if (pu == pv) return;

        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size(); // Total number of stones

        int maxRow = 0, maxCol = 0;

        // Step 1: Maximum row aur column index find karo
        for (auto& it : stones) {
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }

        // Step 2: Disjoint Set ka size row + col + 1 rakhna padega
        // Row node: 0 to maxRow
        // Col node: (maxRow + 1) to (maxRow + maxCol + 1) — isse index clash avoid hoga
        DisjointSet ds(maxRow + maxCol + 1);

        unordered_set<int> uniques; // Set to store unique nodes (row aur column)

        // Step 3: Har stone ka row aur column node connect karo (edge jaisa socho)
        for (auto& it : stones) {
            int nodeRow = it[0];
            int nodeCol = it[1] + maxRow + 1; // Column node ko shift kiya
            ds.unionBySize(nodeRow, nodeCol); // Row aur column ko join kar diya
            uniques.insert(nodeRow);
            uniques.insert(nodeCol);
        }

        // Step 4: Count number of unique connected components
        int cnt = 0;
        for (auto& it : uniques) {
            if (ds.findParent(it) == it) cnt++; // Agar parent khud hai to naya component
        }

        // Step 5: Total stones me se har component me ek stone reh jaayega
        return n - cnt; // Baaki sab remove ho sakte hain
    }
};

int main() {
    Solution sol;

    vector<vector<int>> stones1 = {
        {0, 0}, {0, 1}, {1, 0}, {1, 2}, {2, 1}, {2, 2}
    };
    int result1 = sol.removeStones(stones1);
    cout << "Example 1 Result: " << result1 << endl;

    vector<vector<int>> stones2 = {
        {0, 0}, {0, 2}, {1, 1}, {2, 0}, {2, 2}
    };
    int result2 = sol.removeStones(stones2);
    cout << "Example 2 Result: " << result2 << endl;

    return 0;
}

#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<bool> visited;        // Track karega ki node visit hua hai ya nahi
    vector<int> tin, low;        // tin = discovery time, low = earliest reachable ancestor
    int timer = 1;               // DFS me har node ko ek unique time dene ke liye timer
    vector<vector<int>> bridges; // Saare critical connections store karenge

    // Tarjan's Algorithm based DFS function to find bridges
    void dfs(int node, int parent, vector<vector<int>>& adj) {
        visited[node] = true;
        tin[node] = low[node] = timer++; // Jab first time visit kar rahe, usi ko tin & low dono set karo

        // Sabhi adjacent (connected) nodes pe iterate karo
        for (auto& it : adj[node]) {
            if (it == parent) continue; // Parent pe wapas jaane ka koi faayda nahi

            if (!visited[it]) {
                // Agar adjacent node visit nahi hua hai toh DFS call karo
                dfs(it, node, adj);

                // Wapas aane ke baad apna low update karo based on child ka low
                low[node] = min(low[node], low[it]);

                // Yahan bridge check hota hai:
                // Agar child ka low > current ka discovery time,
                // iska matlab child parent ke bina kisi ancestor pe wapas nahi ja sakta -> bridge hai
                // pehle parent visit hua sirf tab hi hm log child ko visit kr skte hain bina uske hmlog nhi visit krr skte
                if (low[it] > tin[node]) {
                    bridges.push_back({it, node});
                }
            } else {
                // Agar adjacent node already visited hai aur parent nahi hai,
                // toh ek back-edge hai -> low value update karo
                low[node] = min(low[node], tin[it]);
            }
        }
    }

public:
    // Main function to find all bridges in the graph
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        visited.resize(n, false);   // Sab nodes ko initially unvisited mark karo
        tin.resize(n);              // Tin vector resize
        low.resize(n);              // Low vector resize
        vector<vector<int>> adj(n); // Graph ko adjacency list ke form me represent kar rahe

        // Adjacency list banate hain from connections
        for (auto& it : connections) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        // DFS traversal start from node 0
        dfs(0, -1, adj);

        return bridges; // Return the list of bridges
    }
};

int main() {
    Solution sol;

    int n1 = 4;
    vector<vector<int>> connections1 = {{0,1}, {1,2}, {2,0}, {1,3}};
    auto result1 = sol.criticalConnections(n1, connections1);

    cout << "Critical Connections (Bridges) in Graph 1:\n";
    for (auto& bridge : result1) {
        cout << bridge[0] << " - " << bridge[1] << "\n";
    }

    Solution sol2;

    // Test Case 2
    int n2 = 5;
    vector<vector<int>> connections2 = {{1,0}, {2,0}, {3,2}, {4,2}, {4,3}};
    auto result2 = sol2.criticalConnections(n2, connections2);

    cout << "\nCritical Connections (Bridges) in Graph 2:\n";
    for (auto& bridge : result2) {
        cout << bridge[0] << " - " << bridge[1] << "\n";
    }

    return 0;
}

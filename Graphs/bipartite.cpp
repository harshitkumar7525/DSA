#include <bits/stdc++.h>
using namespace std;
bool isBipartite(vector<vector<int>>& graph) {
    int V = graph.size();
    vector<int> color(V, -1);
    queue<int> q;
    for (int i = 0; i < V; i++) {
        if (color[i] == -1) {
            q.push(i);
            color[i] = 0;
            while (!q.empty()) {
                int curr = q.front();
                q.pop();
                int currColor = color[curr];
                int newColor = currColor == 1 ? 0 : 1;
                for (auto& neighbour : graph[curr]) {
                    if (color[neighbour] == currColor) {
                        return false;
                    }
                    if (color[neighbour] == -1) {
                        q.push(neighbour);
                        color[neighbour] = newColor;
                    }
                }
            }
        }
    }
    return true;
}
int main() {
    vector<vector<int>> graph1 = {{1, 2, 3}, {0, 2}, {0, 1, 3}, {0, 2}};
    cout << isBipartite(graph1) << endl;
    vector<vector<int>> graph2 = {{1, 3}, {0, 2}, {1, 3}, {0, 2}};
    cout << isBipartite(graph2) << endl;
    return 0;
}
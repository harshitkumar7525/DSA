#include<bits/stdc++.h>
using namespace std;

class GraphViaAdjacencyMatrix {
    /*
    Space: O(V^2) where V is the number of vertices.
    This is because we are using a 2D vector to represent the adjacency matrix.
    */
private:
    int n; // Number of vertices/nodes
    int m; // Number of edges
    vector<vector<int>> adj; // Adjacency matrix
public:
    GraphViaAdjacencyMatrix(int nodes, int edges) {
        cout<<"This class follows 1-based indexing.\n";
        cout<<"Number of vertices: "<<nodes<<", Number of edges: "<<edges<<endl;
        this->n = nodes;
        this->m = edges;
        this->adj.resize(n + 1,vector<int>(n+1,0)); // Initialize adjacency matrix with 0s
    }
    void addEdge(int u, int v) {
        if(u < 1 || u > n || v < 1 || v > n) {
            cout << "Invalid edge (" << u << ", " << v << "). Vertices must be between 1 and " << n << ".\n";
            exit(1);
        }
        this->adj[u][v] = 1;
        this->adj[v][u] = 1; // If graph is directed, remove this line
    }
    void createGraph() {
        cout << "Enter the edges:\n";
        for(int i = 0; i < m; i++) {
            int u, v; // Edge from u to v
            cout << "Enter edge " << i + 1 << " (u v): ";
            cin >> u >> v;
            addEdge(u, v);
        }
    }
};

class GraphViaAdjacencyList {
    /*
    Space: O(V + E) where V is the number of vertices and E is the number of edges.
    This is because we are using a vector of vectors to represent the adjacency list.
    */
private:
    int n; // Number of vertices/nodes
    int m; // Number of edges
    vector<vector<int>> adj; // Adjacency list

public:
    GraphViaAdjacencyList(int nodes, int edges) {
        cout<<"This class follows 1-based indexing.\n";
        cout<<"Number of vertices: "<<nodes<<", Number of edges: "<<edges<<endl;
        this->n = nodes;
        this->m = edges;
        this->adj.resize(n + 1); // Initialize adjacency list
    }

    void addEdge(int u, int v) {
        if(u < 1 || u > n || v < 1 || v > n) {
            cout << "Invalid edge (" << u << ", " << v << "). Vertices must be between 1 and " << n << ".\n";
            exit(1);
        }
        this->adj[u].push_back(v);
        this->adj[v].push_back(u); // If graph is directed, remove this line
    }

    void createGraph() {
        cout << "Enter the edges:\n";
        for(int i = 0; i < m; i++) {
            int u, v; // Edge from u to v
            cout << "Enter edge " << i + 1 << " (u v): ";
            cin >> u >> v;
            addEdge(u, v);
        }
    }

};

class WeightedGraphViaAdjacencyMatrix {
    /*
    Space: O(V^2) where V is the number of vertices.
    This is because we are using a 2D vector to represent the adjacency matrix with weights.
    */
private:
    int n; // Number of vertices/nodes
    int m; // Number of edges
    vector<vector<int>> adj; // Adjacency matrix with weights

public:
    WeightedGraphViaAdjacencyMatrix(int nodes, int edges) {
        cout<<"This class follows 1-based indexing.\n";
        cout<<"Number of vertices: "<<nodes<<", Number of edges: "<<edges<<endl;
        this->n = nodes;
        this->m = edges;
        this->adj.resize(n + 1, vector<int>(n + 1, 0)); // Initialize adjacency matrix with 0s
    }
    void addEdge(int u, int v, int weight) {
        if(u < 1 || u > n || v < 1 || v > n) {
            cout << "Invalid edge (" << u << ", " << v << "). Vertices must be between 1 and " << n << ".\n";
            exit(1);
        }
        this->adj[u][v] = weight;
        this->adj[v][u] = weight; // If graph is directed, remove this line
    }
};

class WeightedGraphViaAdjacencyList {
    /*
    Space: O(V + E) where V is the number of vertices and E is the number of edges.
    This is because we are using a vector of pairs to represent the adjacency list with weights.
    */
private:
    int n; // Number of vertices/nodes
    int m; // Number of edges
    vector<vector<pair<int, int>>> adj; // Adjacency list with weights
public:
    WeightedGraphViaAdjacencyList(int nodes, int edges) {
        cout<<"This class follows 1-based indexing.\n";
        cout<<"Number of vertices: "<<nodes<<", Number of edges: "<<edges<<endl;
        this->n = nodes;
        this->m = edges;
        this->adj.resize(n + 1); // Initialize adjacency list
    }

    void addEdge(int u, int v, int weight) {
        if(u < 1 || u > n || v < 1 || v > n) {
            cout << "Invalid edge (" << u << ", " << v << "). Vertices must be between 1 and " << n << ".\n";
            exit(1);
        }
        this->adj[u].push_back({v, weight});
        this->adj[v].push_back({u, weight}); // If graph is directed, remove this line
    }

    void createGraph() {
        cout << "Enter the edges (u v w):\n";
        for(int i = 0; i < m; i++) {
            int u, v, w; // Edge from u to v with weight w
            cout << "Enter edge " << i + 1 << " (u v w): ";
            cin >> u >> v >> w;
            addEdge(u, v, w);
        }
    }
};

int main(){
    int n; // Number of vertices/nodes
    int m; // Number of edges
    cout<<"Enter number of vertices and edges: ";
    cin >> n >> m;
    // GraphViaAdjacencyMatrix graph1(n, m);
    // graph1.createGraph();

    GraphViaAdjacencyList graph2(n, m);
    graph2.createGraph();
    cout << "Graphs created successfully.\n";
    return 0;
}
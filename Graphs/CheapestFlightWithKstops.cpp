#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n); // Adjacency list to represent the graph
        for(auto e:flights){ // For each flight, add an edge in the adjacency list
            // e[0] is the source city, e[1] is the destination city, e[2] is the price
            adj[e[0]].push_back(make_pair(e[1],e[2]));
        }
        vector<int> dist(n,INT_MAX); // Distance array to store the minimum cost to reach each city
        dist[src]=0; // Cost to reach the source city is 0
        queue<tuple<int,int,int>> q; // Queue to perform mixture of (BFS + Dijkstra), storing (current stops, current city, current cost)
        q.push(make_tuple(0,src,0));
        while(!q.empty()){
            auto& [currStop, node, cost] = q.front(); // Get the current flight details
            if(currStop>k+1) break; // If we have exceeded the allowed number of stops, break out of the loop
            q.pop(); // Process the current node
            for(auto route:adj[node]){ // For each route from the current city
                // route.first is the destination city, route.second is the cost of the flight
                if(currStop<=k){ // Only consider routes if we are within the allowed number of stops
                    // Calculate the new cost to reach the destination city
                    int newCost = cost + route.second;
                    if(newCost<dist[route.first]){
                        dist[route.first]=newCost;
                        q.push(make_tuple(currStop+1,route.first,newCost));
                    }
                }
            }
        }
        // If the destination city is unreachable, return -1; otherwise, return the minimum cost
        return dist[dst] == INT_MAX ? -1 : dist[dst]; 
    }
};
int main() {
    Solution sol;
    int n = 3; // Number of cities
    vector<vector<int>> flights = {{0, 1, 100}, {1, 2, 100}, {0, 2, 500}}; // Flights represented as {from, to, price}
    int src = 0; // Starting city
    int dst = 2; // Destination city
    int k = 1; // Maximum number of stops allowed

    int result = sol.findCheapestPrice(n, flights, src, dst, k);
    cout << "Cheapest price from " << src << " to " << dst << " with at most " << k << " stops: " << result << endl;

    return 0;
}
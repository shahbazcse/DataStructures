// Link: https://leetcode.com/problems/critical-connections-in-a-network/

// Approach: Tarjan's Algorithm [TC: O(V+2E) / SC: O(V)]

class Solution {
private: 
    int timer = 1; // Timer to keep track of the discovery time of each node during DFS traversal
public:
    void dfs(int node, int parent, vector<int> &vis, vector<int> adj[], int tin[], int low[],
            vector<vector<int>> &bridges) {
        vis[node] = 1;  // Mark the current node as visited
        tin[node] = low[node] = timer;  // Initialize discovery time and low value for the current node
        timer++;

        for(auto it : adj[node]) {  // Iterate through all adjacent nodes of the current node
            if(it == parent) continue;  // Skip the parent node from the iteration

            if(!vis[it]) {  // If the adjacent node is not visited, perform DFS on it
                dfs(it, node, vis, adj, tin, low, bridges);
                low[node] = min(low[node], low[it]);  // Update the low value of the current node

                if(low[it] > tin[node]) {
                    // If the low value of the adjacent node is greater than the discovery time of the current node,
                    // it means that there is no back edge from the adjacent node to any ancestor of the current node.
                    // Thus, the edge (node, it) is a bridge.
                    bridges.push_back({it, node});
                }
            } else {
                low[node] = min(low[node], low[it]);  // Update the low value of the current node
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        // create adjacency list
        vector<int> adj[n]; // adjacency list to represent the graph
        for(auto it : connections){
            adj[it[0]].push_back(it[1]); // add an edge from node it[0] to it[1]
            adj[it[1]].push_back(it[0]); // add an edge from node it[1] to it[0] (since the graph is undirected)
        }

        vector<int> vis(n,0); // visited array to track visited nodes during DFS traversal
        int tin[n]; // array to store the discovery time of each node during DFS traversal
        int low[n]; // array to store the lowest discovery time reachable from each node during DFS traversal
        vector<vector<int>> bridges; // vector to store the critical connections/bridges

        // Depth-First Search (DFS) function to find critical connections
        dfs(0,-1,vis,adj,tin,low,bridges);

        return bridges;
    }
};
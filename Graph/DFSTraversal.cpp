// Link: https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

// Approach: Recursion + Hashing [TC: O(V+2E) / SC: O(V)]

class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfs(int V, vector<int> adj[], int node, vector<int> &vis, vector<int> &ans){
        ans.push_back(node); // store the node
        vis[node] = 1; // mark the node as visited
        
        // loop over the neighbour nodes of the current node
        for(auto it: adj[node]){
            // if the neighbour node is not visited, make recursive call for it
            if(!vis[it]){
                dfs(V,adj,it,vis,ans); // recursive call for neighbour node to traverse further
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ans;

        // visited array to keep track of the visited nodes
        vector<int> vis(V,0);
        
        // DFS Traversal
        dfs(V,adj,0,vis,ans); // passed starting node 0
        
        return ans;
    }
};
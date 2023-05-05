// Link: https://practice.geeksforgeeks.org/problems/eventual-safe-states/1

// Approach: DFS + Hashing [TC: O(V+E) / SC: O(V)]

class Solution {
  public:
    bool dfs(int node, int vis[], int pathVis[], int safeNodes[], vector<int> adj[]){
        vis[node] = 1; // mark nodes as visited
        pathVis[node] = 1; // mark node as visited in current path
        
        for(auto it : adj[node]){
            // if node is unvisited, make recursive call to traverse further
            if(!vis[it]){
                if(dfs(it,vis,pathVis,safeNodes,adj) == true){
                    safeNodes[node] = 0; // mark false if cycle is found in returned recursive calls
                    return true;
                }
            }
            // if nodes is visited and found in the current path again, then there exists a cycle, return true
            else if(pathVis[it]){
                safeNodes[node] = 0; // mark false for if current node forms a cycle
                return true;
            }
        }
        
        safeNodes[node] = 1; // if there don't exist a cycle upto the current node then current node is a safe node, mark it true after backtracking
        pathVis[node] = 0; // mark node unvisited in current path after backtrack
        return false;
    }
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        /*
            1. Nodes that are part of a cycle cannot be a safe node
            2. Nodes that leads to a cycle cannot be a safe node
        */
        
        // to keep track of visited nodes
        int vis[V] = {0};
        // to keep track of unique paths
        int pathVis[V] = {0};
        // to keep track of safe nodes that are not associated with a cycle in any way
        int safeNodes[V] = {-1};
        
        // check for all connected components
        for(int i=0; i<V; i++){
            if(!vis[i]){
                dfs(i,vis,pathVis,safeNodes,adj);
            }
        }
        
        // count safe nodes and return them in ascending order
        vector<int> ans;
        for(int i=0; i<V; i++){
            if(safeNodes[i]==1){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
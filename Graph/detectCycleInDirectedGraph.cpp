// Link: https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

// Approach: DFS + Hashing [TC: O(V+E) / SC: O(V)]

class Solution {
  public:
    bool dfs(int node, int vis[], int pathVis[], vector<int> adj[]){
        vis[node] = 1; // mark nodes as visited
        pathVis[node] = 1; // mark node as visited in current path
        
        for(auto it : adj[node]){
            // if node is unvisited, make recursive call to traverse further
            if(!vis[it]){
                if(dfs(it,vis,pathVis,adj) == true) return true;
            }
            // if nodes is visited and found in the current path again, then there exists a cycle, return true
            else if(pathVis[it]) return true;
        }
        
        pathVis[node] = 0; // mark node unvisited in current path after backtrack
        return false;
    }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // visited node in unique path does not form a cycle, whereas visited node in same/current path form a cycle
        
        // to keep track of visited nodes
        int vis[V];
        // to keep track of unique paths
        int pathVis[V];
        for(int i=0; i<V; i++){
            vis[i]=0;
            pathVis[i]=0;
        }
        
        // check for all connected components
        for(int i=0; i<V; i++){
            if(!vis[i]){
                // if at any point a cycle is found, return true
                if(dfs(i,vis,pathVis,adj)==true) return true;
            }
        }
        return false;
    }
};
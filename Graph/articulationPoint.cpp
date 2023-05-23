// Link: https://practice.geeksforgeeks.org/problems/articulation-point-1/1

// Approach: DFS Traversal [TC: O(V+2E) / SC: O(V)]

class Solution {
    private: 
      int timer = 0; // Timer variable to keep track of the order in which nodes are visited
    
    public:
      void dfs(int node, int parent, vector<int> &vis, vector<int> adj[], int tin[], int low[], vector<int> &markAP) {
            vis[node] = 1; // Mark the current node as visited
            tin[node] = low[node] = timer; // Set the discovery time and low time of the current node
            timer++; // increase timer count by 1 for next node
        
            int child = 0; // Keep track of the number of child nodes of the current node
        
            for(auto it : adj[node]) { // Iterate through the adjacent nodes of the current node
                  if(it == parent) continue; // Skip the node if it is the parent node
            
                  if(!vis[it]) { // If the adjacent node is not visited
                    child++; // increase child count by 1
                    dfs(it, node, vis, adj, tin, low, markAP); // Recursive call to visit the adjacent node
                    low[node] = min(low[node], low[it]); // Update the low time of the current node with the minimum of its low time and the low time of the adjacent node
            
                    if(low[it] >= tin[node] && parent != -1) { // If the low time of the adjacent node is greater than or equal to the discovery time of the current node and the current node is not the root node
                      markAP[node] = 1; // Mark the current node as an articulation point
                    }
                  }
                  else { // If the adjacent node is already visited
                    low[node] = min(low[node], tin[it]); // Update the low time of the current node with the minimum of its low time and the discovery time of the adjacent node
                  }
            }
        
            if(child > 1 && parent == -1) { // If the current node is the root node and has more than one child
              markAP[node] = 1; // Mark the current node as an articulation point
            }
      }
    
      vector<int> articulationPoints(int V, vector<int> adj[]) {
            vector<int> vis(V, 0); // Array to track visited nodes
            int tin[V]; // Array to store discovery time of each node
            int low[V]; // Array to store low time of each node
            vector<int> markAP(V, 0); // Array to mark articulation points
        
            for(int i = 0; i < V; i++) {
              if(!vis[i]) {
                dfs(i, -1, vis, adj, tin, low, markAP); // Perform DFS on each unvisited node
              }
            }
        
            vector<int> ans; // to store the articulation point
            for(int i = 0; i < V; i++) {
              if(markAP[i] == 1) {
                ans.push_back(i); // Add the articulation points to the answer vector
              }
            }
        
            if(ans.size() == 0) {
              return {-1}; // If no articulation points found, return -1
            }
            return ans; // Return the vector of articulation points
      }
};
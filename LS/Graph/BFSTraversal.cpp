// Link: https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

// Approach: Iterative + Queue + Hashing [TC: O(V+E) / SC: O(V)]

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ans;
        
        // visited array to keep track of the visited nodes
        int vis[V]={0};
        
        // queue to do BFS traversal by storing neighbour nodes of current node
        queue<int> q;
        q.push(0);
        vis[0] = 1;
        
        // BFS Traversal
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            
            ans.push_back(node);
            
            for(auto it: adj[node]){
                if(!vis[it]){
                    q.push(it);
                    vis[it] = 1;
                }
            }
        }
        
        return ans;
    }
};
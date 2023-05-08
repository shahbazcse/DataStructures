// Link: https://practice.geeksforgeeks.org/problems/eventual-safe-states/1

// Approach: BFS + Topological Sort + Sorting [TC: O(V + E + NlogN) / SC: O(2V)]

/*
    1. Reverse the all directed edges
    2. Do topological sort using BFS for reversed adjacency list
*/

class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<int> adjRev[V]; // reversed adjacency list
        int indegree[V] = {0};
        for(int i=0; i<V; i++){
            for(auto it : adj[i]){
                adjRev[it].push_back(i); // reversing the directed edges
                indegree[i]++; // counting incoming edges to the current node
            }
        }

        // Topological sort        
        queue<int> q;
        for(int i=0; i<V; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        
        vector<int> safeNodes;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);
            
            for(int it : adjRev[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        
        sort(safeNodes.begin(),safeNodes.end()); // sorting nodes in ascending order
        return safeNodes;
    }
};
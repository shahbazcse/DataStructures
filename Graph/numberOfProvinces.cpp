// Link: https://practice.geeksforgeeks.org/problems/number-of-provinces/1

// Approach: DFS + Hashing [TC: O(V+(V+2E)) / SC: O(V)]

class Solution {
  public:
    // DFS Traversal
    void dfs(int node, vector<int> adjList[], int vis[]){
        vis[node] = 1;
        
        for(auto it: adjList[node]){
            if(!vis[it]){
                dfs(it,adjList,vis);
            }
        }
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        vector<int> adjList[V];
        
        // creating adjacency list
        for(int i=0; i<V; i++){
            for(int j=0; j<V; j++){
                if(adj[i][j]==1 && i!=j){
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
        
        // count to keep track of provinces
        int cnt=0;
        
        // hash array to keep track of visited nodes
        int vis[V] = {0};
        
        // Perform DFS for every node as starting node untill all nodes are visited
        for(int i=0; i<V; i++){
            if(!vis[i]){
                dfs(i,adjList,vis);
                cnt++;
            }
        }
        
        return cnt;
    }
};
// Link: https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1

// Approach: BFS Traversal [TC: O(N+M) / SC: O(N)]

class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // creating adjacency list
        vector<int> adj[N];
        for(int i=0; i<M; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        // BFS Traversal
        queue<int> q;
        q.push(src);
        
        int dist[N]; // for storing shortest distance of current node from 'src' node
        for(int i=0; i<N; i++) dist[i] = 1e9;
        dist[src] = 0; // distance from 'src' to 'src' will be 0
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto it : adj[node]){
                // shortest distance logic
                if(dist[node] + 1 < dist[it]){
                    dist[it] = dist[node] + 1;
                    q.push(it);
                }
            }
        }
        
        // storing array 'dist' to vector 'ans'
        vector<int> ans(N,-1);
        for(int i=0; i<N; i++){
            if(dist[i] != 1e9){
                ans[i] = dist[i];
            }
        }
        return ans;
    }
};
// Link: https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1

// Approach: DFS + Topological Sort [TC: O(N+M) / SC: O(N)]

class Solution {
  public:
    void topoSort(int node, vector<pair<int,int>> adj[], int vis[], stack<int> &st){
        vis[node] = 1;
        
        for(auto it : adj[node]){
            int v = it.first;
            if(!vis[v]){
                topoSort(v,adj,vis,st);
            }
        }
        
        st.push(node);
    }
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // creating adjacency list
        vector<pair<int,int>> adj[N];
        for(int i=0; i<M; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v,wt});
        }
        
        // topological sort
        int vis[N] = {0};
        stack<int> st;
        for(int i=0; i<N; i++){
            if(!vis[i]){
                topoSort(i,adj,vis,st);
            }
        }
        
        // find the minimum distance from source to current node
        vector<int> dist(N,1e9);
        dist[0] = 0;
        
        while(!st.empty()){
            int node = st.top();
            st.pop();
            
            for(auto it : adj[node]){
                int v = it.first;
                int wt = it.second;
                
                // shortest path logic
                if(dist[node] + wt < dist[v]){
                    dist[v] = dist[node] + wt;
                }
            }
        }
        
        // problem requirement for unreachable nodes from source node
        for(int i=0; i<dist.size(); i++){
            if(dist[i] == 1e9){
                dist[i] = -1;
            }
        }
        
        return dist;
    }
};
// Link: https://practice.geeksforgeeks.org/problems/longest-path-in-a-directed-acyclic-graph/1

// Approach: DFS + Topological Sort [TC: O(V+E) / SC: O(V)]

class Solution
{
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
    vector<int> maximumDistance(vector<vector<int>> edges,int v,int e,int src)
    {
        // creating adjacency list
        vector<pair<int,int>> adj[v];
        for(int i=0; i<e; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v,wt});
        }
        
        // topological sort
        int vis[v] = {0};
        stack<int> st;
        topoSort(src,adj,vis,st);
        
        // find the longest distance from source to current node
        vector<int> dist(v,INT_MIN);
        dist[src] = 0;
        
        while(!st.empty()){
            int node = st.top();
            st.pop();
            
            for(auto it : adj[node]){
                int v = it.first;
                int wt = it.second;
                
                // longest path logic
                if(dist[node] + wt > dist[v]){
                    dist[v] = dist[node] + wt;
                }
            }
        }
        
        return dist;
    }
};
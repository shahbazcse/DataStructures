// Link: https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1

// Approach: Kosaraju's Algorithm [TC: O(V+E) / SC: O(V+E)]

/*
    Strongly Connected Component is only valid for Directed Graphs
*/

class Solution
{
	public:
	// DFS to sort all the nodes according to their finishing time
	void dfs(int node, vector<int> &vis, stack<int> &st, vector<vector<int>> &adj){
	    vis[node] = 1;
	    
	    for(auto it : adj[node]){
	        if(!vis[it]){
	            dfs(it,vis,st,adj);
	        }
	    }
	    
	    st.push(node);
	}
	// DFS to count SCC
	void dfs2(int node, vector<int> &vis, vector<int> adjR[]){
	    vis[node] = 1;
	    
	    for(auto it : adjR[node]){
	        if(!vis[it]){
	            dfs2(it,vis,adjR);
	        }
	    }
	}
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        vector<int> vis(V,0);
        
        // Step 1: sort all the nodes according to their finishing time
        stack<int> st;
        for(int i=0; i<V; i++){
            if(!vis[i]){
                dfs(i,vis,st,adj);
            }
        }
        
        // Step 2: reverse the directed edges
        vector<int> adjR[V];
        for(int i=0; i<V; i++){
            vis[i] = 0;
            // i -> it (original edges)
            for(auto it : adj[i]){
                // it -> i (reversed edges)
                adjR[it].push_back(i);
            }
        }
        
        // Step 3: Do DFS Traversal to count SCC
        int scc = 0;
        while(!st.empty()){
            int node  = st.top();
            st.pop();
            
            if(!vis[node]){
                scc++;
                dfs2(node,vis,adjR);
            }
        }
        
        return scc;
    }
};
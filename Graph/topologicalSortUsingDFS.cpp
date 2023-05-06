// Link: https://practice.geeksforgeeks.org/problems/topological-sort/1

// Approach: DFS + Hashing + Stack [TC: O(V+E) / SC: O(V)]

/*
    1. Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that 
    for every directed edge u v, vertex u comes before v in the ordering.

    2. Topological Sorting for a graph is not possible if the graph is not a DAG (Directed-Acyclic-Graph).
*/

class Solution
{
	public:
	void dfs(int node, int vis[], vector<int> adj[], stack<int> &st){
	    vis[node] = 1;
	    
	    for(int it : adj[node]){
	        if(!vis[it]){
	            dfs(it,vis,adj,st);
	        }
	    }
	    // store the current node in stack after making the recursive calls for its adjacent nodes above, because current node will always come before its adjacent nodes
	    st.push(node);
	}
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
        // to keep track of the visited nodes
	    int vis[V] = {0};
        // for storing the nodes in topologically sorted order after visiting the node
	    stack<int> st;
	    
	    for(int i=0; i<V; i++){
	        if(!vis[i]){
	            dfs(i,vis,adj,st);
	        }
	    }
	    
	    vector<int> ans;
	    while(!st.empty()){
	        ans.push_back(st.top());
	        st.pop();
	    }
	    return ans;
	}
};
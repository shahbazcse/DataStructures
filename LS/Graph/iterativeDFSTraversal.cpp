// Link: https://www.geeksforgeeks.org/iterative-depth-first-traversal/

// Approach: DFS + Iterative + Stack [TC: O(V+E) / SC: O(V)]

#include<bits/stdc++.h>
using namespace std;

void addEdge(int v, int w, vector<int> adj[])
{
	adj[v].push_back(w); // Add w to v’s list.
    adj[w].push_back(v); // Add v to w’s list.
}

// prints all not yet visited vertices reachable from node 0
vector<int> iterativeDFS(int V, vector<int> adj[])
{
		vector<int> dfs;

        // keep track of the visited nodes
  		vector<int> vis(V,0);
        
        // iterative DFS traversal;
        stack<int> st;
        st.push(0);
        vis[0] = 1;
        
        while(!st.empty()){
            int node = st.top();
            dfs.push_back(node);
            st.pop();
            
            // check for adjacency list of current 'node'
            for(auto it : adj[node]){
                // if neighbour node is not visited, mark it as visited, and push it into stack
                if(!vis[it]){
                    vis[it] = 1;
                    st.push(it);
                }
            }
        }
  
  		return dfs;
}

// Driver program to test methods of graph class
int main()
{
    int V=5;
	vector<int> adj[V];
	
    // create and connect nodes
	addEdge(1, 0, adj);
	addEdge(0, 2, adj);
	addEdge(2, 1, adj);
	addEdge(0, 3, adj);
	addEdge(1, 4, adj);

	cout << "Following is Depth First Traversal\n";
	;
  
  	vector<int> ans = iterativeDFS(V,adj);
    
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

	return 0;
}
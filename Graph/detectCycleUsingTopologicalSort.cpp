// Link: https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

// Approach: BFS + Topological Sort [TC: O(V+E) / SC: O(V)]

class Solution {
  public:
    vector<int> topoSort(int V, vector<int> adj[]){
        int indegree[V] = {0};
	    for(int i=0; i<V; i++){
	        for(auto it: adj[i]){
	            indegree[it]++;
	        }
	    }
	    
        // to perform BFS traversal
	    queue<int> q;

	    for(int i=0; i<V; i++){
            // if there are no outgoing edges from a node, then store it in topologically sorted order
	        if(indegree[i]==0){
	            q.push(i);
	        }
	    }
	    
	    vector<int> topo;

        // BFS traversal
	    while(!q.empty()){
	        auto node = q.front();
	        q.pop();
	        topo.push_back(node); // topological sorted order
	        
	        for(int it: adj[node]){
	            indegree[it]--; // after visiting the adjacent node, decrement its degree by 1
	            // if the indegree of the adjacent node becomes 0, store it in topological sorted order
                if(indegree[it]==0){
	                q.push(it);
	            }
	        }
	    }
	    return topo;
    }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> ans = topoSort(V,adj); // store the topologically sorted order of nodes
        
        /*
            Topological sort works on DAG and it always returns the sorted order of all the nodes in the graph, 
            so if there are nodes != V, then the graph must have a cycle, return true
        */

        if(ans.size()!=V) return true;
        else return false; // if there are no cycles present (topo sort returns nodes == V), return false
    }
};
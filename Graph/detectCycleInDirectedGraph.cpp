// Link: https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

// Approach 1: DFS + Hashing [TC: O(V+E) / SC: O(V)]

class Solution {
  public:
    bool dfs(int node, int vis[], int pathVis[], vector<int> adj[]){
        vis[node] = 1; // mark nodes as visited
        pathVis[node] = 1; // mark node as visited in current path
        
        for(auto it : adj[node]){
            // if node is unvisited, make recursive call to traverse further
            if(!vis[it]){
                if(dfs(it,vis,pathVis,adj) == true) return true;
            }
            // if nodes is visited and found in the current path again, then there exists a cycle, return true
            else if(pathVis[it]) return true;
        }
        
        pathVis[node] = 0; // mark node unvisited in current path after backtrack
        return false;
    }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // visited node in unique path does not form a cycle, whereas visited node in same/current path form a cycle
        
        // to keep track of visited nodes
        int vis[V];
        // to keep track of unique paths
        int pathVis[V];
        for(int i=0; i<V; i++){
            vis[i]=0;
            pathVis[i]=0;
        }
        
        // check for all connected components
        for(int i=0; i<V; i++){
            if(!vis[i]){
                // if at any point a cycle is found, return true
                if(dfs(i,vis,pathVis,adj)==true) return true;
            }
        }
        return false;
    }
};

// Approach 2: BFS + Topological Sort [TC: O(V+E) / SC: O(V)]

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
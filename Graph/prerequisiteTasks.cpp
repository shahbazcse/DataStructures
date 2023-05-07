// Link: https://practice.geeksforgeeks.org/problems/prerequisite-tasks/1

// Approach: BFS + Topological Sort [TC: O() / SC: O()]

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
    
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
        // creating adjacency list
	    vector<int> adj[N];
	    for(auto it : prerequisites){
	        adj[it.first].push_back(it.second);
	    }
	    
	    vector<int> ans = topoSort(N,adj);

        /*
            Topological sort works on DAG and it always returns the sorted order of all the nodes in the graph, 
            so if nodes == V, then there is no cycle present or no cyclic dependency for tasks to complete,
            thus we can use topological sort to check whether cyclic dependency for tasks is present or not
        */
	    
        // if there are no cycles or no cyclic dependency for tasks present (topo sort returns nodes == V), return true
        if(ans.size()==N) return true;
        else return false; 
	}
};
// Link: https://practice.geeksforgeeks.org/problems/topological-sort/1

// Approach: BFS + Hashing + Indegree Array [TC: O(V+E) / SC: O(V)]

class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{   
        // to store the number of outgoing edges from a node
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
	    
	    vector<int> ans;

        // BFS traversal
	    while(!q.empty()){
	        auto node = q.front();
	        q.pop();
	        ans.push_back(node); // topological sorted order
	        
	        for(int it: adj[node]){
	            indegree[it]--; // after visiting the adjacent node, decrement its degree by 1
	            // if the indegree of the adjacent node becomes 0, store it in topological sorted order
                if(indegree[it]==0){
	                q.push(it);
	            }
	        }
	    }
	    return ans;
	}
};
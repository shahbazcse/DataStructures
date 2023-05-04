// Link: https://practice.geeksforgeeks.org/problems/bipartite-graph/1

// Approach 1: BFS + Hashing [TC: O(V+2E) / SC: O(V)]

class Solution {
public:
    bool check(int start, vector<int> adj[], int color[]){
	    color[start] = 0; // color the starting node with 0
	    
	    queue<int> q;
	    q.push(start);
	    
	    while(!q.empty()){
	        int node = q.front();
	        q.pop();
	        
	        for(auto it : adj[node]){
                // if node is not visited and not colored
	            if(color[it] == -1){
	                color[it] = !color[node]; // color the node with opposite color of the adjacent node (parent node)
	                q.push(it); // and store it in queue
	            }
                // if the node is visited and it has same color as its adjacent node (parent node), then graph is not bipartite
	            else if(color[it] == color[node]){
	                return false;
	            }
	        }
	    }
	    return true;
    }
	bool isBipartite(int V, vector<int>adj[]){
        // keep track of the visited nodes and their alterate color behaviour
        int color[V];
	    for(int i=0; i<V; i++) color[i] = -1;
	    
        // check for all connected components
	    for(int i=0; i<V; i++){
	        if(color[i] == -1){
	            if(check(i,adj,color) == false) return false;
	        }
	    }
	    return true;
	}
};

// Approach 2: DFS + Hashing [TC: O(V+2E) / SC: O(V)]

class Solution {
public:
    bool check(int start, int color[], vector<int> adj[]){
	    for(auto it : adj[start]){
	        if(color[it]==-1){
	            color[it] = !color[start];
	            if(check(it,color,adj) == false) return false;
	        }else if(color[it] == color[start]){
	            return false;
	        }
	    }
	    return true;
    }
	bool isBipartite(int V, vector<int>adj[]){
	    int color[V];
	    for(int i=0; i<V; i++) color[i]=-1;
	    
	    for(int i=0; i<V; i++){
	        if(color[i]==-1){
	            color[i] = 0;
	            if(check(i,color,adj) == false) return false;
	        }
	    }
	    return true;
	}
};
// Link: https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

// Approach 1: BFS Traversal [TC: O(V+2E) / SC: O(V)]

class Solution {
  public:
    bool detectUsingBFS(int src, vector<int> adj[], int vis[]){
        vis[src] = 1;
        
        queue<pair<int,int>> q;
        q.push({src,-1});
        
        while(!q.empty()){
            int node = q.front().first;
            int parentNode = q.front().second;
            q.pop();
            
            for(auto neighbourNode : adj[node]){
                if(!vis[neighbourNode]){
                    vis[neighbourNode] = 1;
                    q.push({neighbourNode,node});
                }
                /*  if the 'neighbourNode' is already visited and it is not the parent, 
                    then that 'neighbourNode' must be visited by some other node in the same level, 
                    which means the graph is cyclic.
                */
                else if(parentNode != neighbourNode){
                    return true;
                }
            }
        }
        return false;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        int vis[V] = {0};
        
        // checking for all connected components
        for(int i=0; i<V; i++){
            if(!vis[i]){
                if(detectUsingBFS(i,adj,vis)) return true;
            }
        }
        return false;
    }
};

// Approach 2: DFS Traversal [TC: O() / SC: O()]

class Solution {
  public:
    bool detectUsingDFS(int src, int parent, vector<int> adj[], int vis[]){
        vis[src] = 1;
        
        for(auto node : adj[src]){
            if(!vis[node]){
                // if a cyclic graph component is found in the recursive call, return true
                if(detectUsingDFS(node,src,adj,vis)){
                    return true;
                }
            }
            /*  if the 'node' is already visited and it is not the parent, 
                then that 'node' must be visited by some other node in the recursion tree before, 
                which means the graph is cyclic.
            */
            else if(node!=parent){
                return true;
            }
        }
        // if no cyclic graph component is found in the recursive call, return false
        return false;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        int vis[V] = {0};
        
        // checking for all connected components
        for(int i=0; i<V; i++){
            if(!vis[i]){
                if(detectUsingDFS(i,-1,adj,vis)){
                    return true;
                }
            }
        }
        return false;
    }
};
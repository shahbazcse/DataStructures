// Link: https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1

// Approach: [TC: O(E*Log(E)) / SC: O(V+E)]

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // create a min heap using priority queue
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        // {weight,node}
        pq.push({0,0});
        
        // to keep track of the visited nodes
        vector<int> vis(V,0);
        
        // minimum sum of edge weights needed to construct a MST
        int sum = 0;
        
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int wt = it.first;
            int node = it.second;
            
            // if the node is already visited, skip the node
            if(vis[node]) continue;
            
            // if the node is not visited, mark it as visited
            vis[node] = 1;
            
            // add the path weight
            sum += wt;
            
            // traverse adjacent nodes of the current node
            for(auto it : adj[node]){
                int adjNode = it[0];
                int edgeWeight = it[1];
                
                // if the node is not visited, add it to the queue
                if(!vis[adjNode]){
                    pq.push({edgeWeight,adjNode});
                }
            }
        }
        
        return sum;
    }
};
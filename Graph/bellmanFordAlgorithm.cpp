// Link: https://practice.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1

// Approach: [TC: O(V*E) / SC: O(V)]

/*
    1. Bellman Ford Algorithm is used to find the shortest path from source to nodes.
    2. It is used for graph with negative weights.
    3. Bellman Ford Algorithm will only work for Directed Graph.
    4. If we have a Undirected Graph, we must convert it into a Directed Graph.
*/

class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        vector<int> dist(V,1e8);
        dist[S] = 0;
        
        int it = V-1;
        
        // Relax all the edges n-1 times and update the shortest path from source node to remaining nodes
        while(it--){
            for(int i=0; i<edges.size(); i++){
                int u = edges[i][0];
                int v = edges[i][1];
                int wt = edges[i][2];
                if(dist[u] + wt < dist[v]){
                    dist[v] = dist[u] + wt;
                }
            }
        }
        
        // Nth relaxation to check negative cycle
        for(int i=0; i<edges.size(); i++){
                int u = edges[i][0];
                int v = edges[i][1];
                int wt = edges[i][2];
                if(dist[u] + wt < dist[v]){
                    return {-1};
                }
        }
            
        return dist;
    }
};
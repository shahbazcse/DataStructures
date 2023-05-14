// Link: https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

// Approach 1: [TC: O(E*Log(V)) / SC: O(V)]

/*
    Time and Space Complexity:

    Explanation:

    1. The while loop runs for V iterations because each vertex is processed only once.
    2. For each vertex, the algorithm explores all its adjacent edges, resulting in a total of E iterations.
    3. The priority queue (implemented as a min-heap) operations take O(log V) time complexity.
    4. Therefore, the overall time complexity is O((V + E) log V).
*/

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Min Heap
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq; // SC: O(V)
        
        vector<int> dist(V,1e9); // SC: O(V)
        
        dist[S] = 0;
        pq.push({0,S});
        
        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto it :  adj[node]){
                int adjNode = it[0];
                int edgeWeight = it[1];
                if(dis + edgeWeight < dist[adjNode]){
                    dist[adjNode] = dis + edgeWeight;
                    pq.push({dist[adjNode],adjNode});
                }
            }
        }
        return dist;
    }
};


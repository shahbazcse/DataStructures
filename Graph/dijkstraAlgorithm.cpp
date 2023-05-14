// Link: https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

// Approach 1: Using Priority Queue [TC: O((V+E)*Log(V)) / SC: O(V)]

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

// Approach 2: Using Sets [TC: O((V+E)*Log(V)) / SC: O(V)]

/*
    Time and Space Complexity:

    Explanation:

    1. The while loop runs for V iterations because each vertex is processed only once.
    2. For each vertex, the algorithm explores all its adjacent edges, resulting in a total of E iterations.
    3. The set operations, such as insertion and deletion, take O(log V) time complexity.
    4. Therefore, the overall time complexity is O((V + E) log V).
*/

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Set DS
        set<pair<int,int>> st;
        
        vector<int> dist(V,1e9);
        
        dist[S] = 0;
        st.insert({0,S});
        
        while(!st.empty()){
            auto top = *(st.begin());
            
            int dis = top.first;
            int node = top.second;
            
            st.erase(top);
            
            for(auto it :  adj[node]){
                int adjNode = it[0];
                int edgeWeight = it[1];
                if(dis + edgeWeight < dist[adjNode]){
                    // if a distance already exists, delete it before inserting a smaller distance
                    if(dist[adjNode] != 1e9){
                        st.erase({dist[adjNode], adjNode});
                    }
                    
                    dist[adjNode] = dis + edgeWeight;
                    st.insert({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
    }
};
// Link: https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1

// Approach: Kruskal's Algorithm using Disjoint Set [TC: O(MLogM) / SC: O(M)] // M  = V+E 

// Disjoint Set Data Structure
class DisjointSet{
    vector<int> rank,parent,size;
public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1,0);
        size.resize(n+1);
        for(int i=0; i<=n; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }
    
    int findUltimateParent(int node){
        if(node == parent[node]) return node;
        else return parent[node] = findUltimateParent(parent[node]);
    }
    
    // Union By Rank
    void unionByRank(int u, int v){
        int ulp_u = findUltimateParent(u);
        int ulp_v = findUltimateParent(v);
        
        if(ulp_u == ulp_v) return;
        
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }else if(rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    
    // Union By Size
    void unionBySize(int u, int v){
        int ulp_u = findUltimateParent(u);
        int ulp_v = findUltimateParent(v);
        
        if(ulp_u == ulp_v) return;
        
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // create a list of edges
        // SC: O(V+E)
        vector<pair<int,pair<int,int>>> edges;

        // TC: O(V+E)
        for(int i=0; i<V; i++){
            for(auto it : adj[i]){
                int node = i; // current node
                int adjNode = it[0]; // neighbour node
                int wt = it[1]; // weight between current and neighbour node
                
                edges.push_back({wt,{node,adjNode}}); // store it in list
            }
        }
        
        // sort the edges list
        // TC: (MLogM) // M = V+E
        sort(edges.begin(),edges.end());

        // create a disjoint set for the edges
        DisjointSet ds(V);
        
        // minimum sum of edge weights needed to construct a MST
        int mstWeight = 0;
        
        // traverse through all the edges in a sorted manner
        // TC: O(M x 4 x alpha x 2) or O(M) // Since 4, alpha, 2 are constants
        for(auto it :  edges){
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            
            // if both the nodes are not in the same component, they do not share the same ultimate parent
            if(ds.findUltimateParent(u) != ds.findUltimateParent(v)){
               mstWeight += wt; // add their path weights
               ds.unionBySize(u,v); // merge the node with smaller component size, with the node with the larger component size
            }
        }
        
        return mstWeight; // return minimum sum of edge weights needed to construct a MST
    }
};
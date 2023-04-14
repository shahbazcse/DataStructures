// Link: https://practice.geeksforgeeks.org/problems/print-adjacency-list-1587115620/1

// Approach: Recursion [TC: O(V*E) / SC: O(2*E)]

class Solution {
  public:
    // Function to return the adjacency list for each vertex.
    void solve(int V, vector<int> adj[], vector<vector<int>> &ans, int idx){
        if(idx==V) return;
        
        vector<int> temp;
        temp.push_back(idx);
        for(int i=0; i<adj[idx].size(); i++){
            temp.push_back(adj[idx][i]);
        }
        ans.push_back(temp);
        
        solve(V,adj,ans,idx+1);
    }
    vector<vector<int>> printGraph(int V, vector<int> adj[]) {
        vector<vector<int>> ans;
        solve(V,adj,ans,0);
        return ans;
    }
};
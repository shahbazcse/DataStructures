// Link: https://leetcode.com/problems/combinations/

// Approach: [TC: O(2^N) / SC: O(2^N)]

class Solution {
public:
    void solve(int n, int k, vector<vector<int>> &ans, vector<int> &ds, int idx){
        if(ds.size()==k){
            ans.push_back(ds);
            return;
        }

        for(int i=idx; i<=n; i++){
            ds.push_back(i);
            solve(n,k,ans,ds,i+1);
            ds.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> ds;
        solve(n,k,ans,ds,1);
        return ans;
    }
};
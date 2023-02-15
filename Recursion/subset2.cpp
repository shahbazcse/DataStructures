// Link: https://practice.geeksforgeeks.org/problems/subset-sum-ii/1

// Approach: [TC: O((2^N)*K) / SC: O((2^N)*K)]

class Solution {

  public:
    void solve(vector<int> nums, vector<vector<int>> &ans, vector<int> &ds, int idx){
        if(idx>=nums.size()){
            ans.push_back(ds);
            return;
        }
        
        ds.push_back(nums[idx]);
        solve(nums,ans,ds,idx+1);
        ds.pop_back();
        
        solve(nums,ans,ds,idx+1);
    }
    vector<vector<int>> printUniqueSubsets(vector<int>& nums) {
        vector<vector<int>> ans,res;
        vector<int> ds;
        
        sort(nums.begin(),nums.end());
        
        solve(nums,ans,ds,0);
        
        // remove duplicate subsets
        set<vector<int>> s;
        
        for(auto it:ans) s.insert(it);
        
        for(auto it:s) res.push_back(it);
        
        return res;
    }
};
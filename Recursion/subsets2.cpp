// Link: https://leetcode.com/problems/subsets-ii/description/

// Approach 1: Recursion + Sets [TC: O(2^N+(2^NLog(2^N))) / SC: O(2^N)]

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
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
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

// Approach 2: Recursion Optimized [TC: O((2^N)*N) / Aux. SC: O(2^N)]

class Solution {
public:
    void subsets(int idx, vector<int> &nums, vector<int> &ds, vector<vector<int>> &ans){
        ans.push_back(ds);
        for(int i=idx; i<nums.size(); i++){
            if(i!=idx && nums[i]==nums[i-1]) continue; // ignore duplicates
            // Take
            ds.push_back(nums[i]);
            subsets(i+1,nums,ds,ans);
            ds.pop_back();
        }
        return;
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> ds;
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        subsets(0,nums,ds,ans);
        return ans;
    }
};
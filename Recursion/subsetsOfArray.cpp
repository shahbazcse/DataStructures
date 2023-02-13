// Link: https://leetcode.com/problems/subsets/

// Approach: [TC: O(2^N) / SC: O(N)]

class Solution {
public:
    void solve(vector<int> nums, vector<vector<int>> &ans, vector<int> &ds, int idx){
        if(idx==nums.size()){
            ans.push_back(ds);
            return;
        }

        ds.push_back(nums[idx]);
        solve(nums,ans,ds,idx+1);
        ds.pop_back();

        solve(nums,ans,ds,idx+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        
        solve(nums,ans,ds,0);

        return ans;
    }
};
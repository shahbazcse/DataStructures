class Solution {
public:
    void subsets(int idx, vector<int> &nums, vector<int> &ds, vector<vector<int>> &ans){
        ans.push_back(ds);
        for(int i=idx; i<nums.size(); i++){
            if(i!=idx && nums[i]==nums[i-1]) continue;
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
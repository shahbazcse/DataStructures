// Link: https://leetcode.com/problems/find-all-duplicates-in-an-array/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ds;
        sort(nums.begin(),nums.end());
        for(int i=1; i<nums.size(); i++){
            if(nums[i-1]==nums[i]) ds.push_back(nums[i-1]);
        }
        return ds;
    }
};
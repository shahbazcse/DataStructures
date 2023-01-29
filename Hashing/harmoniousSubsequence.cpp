// Link: https://leetcode.com/problems/longest-harmonious-subsequence/

// Approach: Using Hashing [TC: O(N) / SC: O(N)] 

class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int> m;

        for(auto i:nums) m[i]++;

        int maxi=0;
        for(int i=0; i<nums.size(); i++){
            if(m[nums[i]+1]){
                int count=m[nums[i]]+m[nums[i]+1];
                maxi=max(maxi,count);
            }
        }
        return maxi;
    }
};
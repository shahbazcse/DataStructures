// Link: https://leetcode.com/problems/two-sum/

// Approach 1: [TC: O(N^2) / SC: O(1)]
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        int sum=0;
        for(int i=0; i<nums.size(); i++){
            for(int j=i+1; j<nums.size(); j++){
                if(nums[i]+nums[j]==target){
                    ans.push_back(i);
                    ans.push_back(j);
                }
            }
        }
        return ans;
    }
};

// Approach 2: Map [TC: O(N) / SC: O(N)]

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int first = -1;
        int last = -1;

        unordered_map<int,int> mpp;

        for(int i=0; i<nums.size(); i++){
            first = i;
            int key = target - nums[i];

            auto itr = mpp.find(key);
            
            if(itr!=mpp.end()){
                last = itr->second;
                break;
            }
            mpp[nums[i]] = i;
        }

        return {first,last};
    }
};
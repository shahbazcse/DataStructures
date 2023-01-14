// Link: https://leetcode.com/problems/rearrange-array-elements-by-sign/

// Approach 1: With 3 vectors [TC: O(N)]

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos;
        vector<int> neg;
        vector<int> ans;

        for(int i=0; i<nums.size(); i++){
            if(nums[i]>=0)
                pos.push_back(nums[i]);
            else
                neg.push_back(nums[i]);
        }
        for(int i=0; i<nums.size()/2; i++){
            ans.push_back(pos[i]);
            ans.push_back(neg[i]);
        }
        return ans;
    }
};

// Approach 2: Optimized: With 1 vector [TC: O(N)]

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans(nums.size(),0);
        int idxPos = 0, idxNeg=1;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]>0){
                ans[idxPos] = nums[i];
                idxPos+=2;
            }
            if(nums[i]<0){
                ans[idxNeg] = nums[i];
                idxNeg += 2;
            }
        }
        return ans;
    }
};
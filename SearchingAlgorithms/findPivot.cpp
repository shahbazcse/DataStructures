// Link: 

// Approach: [TC: O(N)]

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int rightSum=0;
        for(int i=0; i<nums.size(); i++) rightSum+=nums[i];
        int leftSum=0;
        int i=0;
        while(i<nums.size()){
            rightSum-=nums[i];
            if(leftSum==rightSum) return i;
            leftSum+=nums[i];
            i++;
        }
        return -1;
    }
};
// Link: https://leetcode.com/problems/move-zeroes/

// Approach: [TC:: O(N) / SC: O(1)]

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0;
        int j=0;

        while(j+1<=nums.size()){
            if(nums[i]==0 && nums[j]!=0){
                swap(nums[i],nums[j]);
                i++;
                j=i+1;
            }else if(nums[i] == 0 && nums[j] == 0){
                j++;
            }else{
                i++;
                j++;
            }
        }
    }
};
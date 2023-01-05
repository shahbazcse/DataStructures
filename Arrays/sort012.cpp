// Link: https://leetcode.com/problems/sort-colors/

// Approach 1: Sorting - TC: O(nlogn)

class Solution {
public:
    void sortColors(vector<int>& nums) {
        for(int i=1; i<nums.size(); i++){
            if(nums[i-1]>nums[i]){
                swap(nums[i-1],nums[i]);
                i=0;
            }
        }
    }
};

// Approach 2: Using Dutch National Flag Algorithm

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low=0;
        int mid=0;
        int high=nums.size()-1;
        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[mid],nums[low]);
                mid++;
                low++;
            }else if(nums[mid]==1){
                mid++;
            }else if(nums[mid]==2){
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }
};
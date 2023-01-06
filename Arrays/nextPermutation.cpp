// Link: https://leetcode.com/problems/next-permutation/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // Traversing from last element and find the point where descending order breaks
        int i=nums.size()-2;
        while(i>=0 && nums[i]>=nums[i+1]){
            i--;
        }
        /*
        Checking if i>=0, breaking point is present in array, 
        if no breaking point is present, the array is in descending order 
        and hence i=-1, so we just reverse the array
        */
        if(i>=0){
            // Traversing from last element upto the ith+1 index and finding the first element greater than ith index
            int j=nums.size()-1;
            while(j>=0 && nums[j]<=nums[i]) j--;
            swap(nums[i],nums[j]); // Swapping the values
        }
        reverse(nums.begin()+i+1,nums.end()); // Reversing the from ith+1 index element to the last element
    }
};
// Link: https://leetcode.com/problems/rotate-array/
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> temp(n);
        // Rotating the array;
        for(int i=0; i<n; i++){
            temp[(i+k)%n]=nums[i];
        }
        // Copying temp in nums
        nums = temp;
    }
};
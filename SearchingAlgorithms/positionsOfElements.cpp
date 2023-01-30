// Link: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

// Approach 1: Brute Force [TC: O(N)]

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first=-1;
        int last=-1;
        int i=0;
        for(i=0; i<nums.size(); i++){
            if(nums[i]==target){
                first=i;
                break;
            }
        }
        for(int j=nums.size()-1; j>=i; j--){
            if(nums[j]==target){
                last=j;
                break; 
            }
        }
        return {first, last};
    }
};

// Approach 2: Binary Search [TC: O(LogN)]

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2,-1);

        int s=0;
        int e=nums.size()-1;

        while(s<=e){
            int mid=s+(e-s)/2;
            if(nums[mid]==target){
                ans[0]=mid;
                e=mid-1; // shrinking search space from right to get the first position
            }
            else if(nums[mid]<target) s=mid+1;
            else e=mid-1;
        }

        s=0;
        e=nums.size()-1;

        while(s<=e){
            int mid=s+(e-s)/2;
            if(nums[mid]==target){
                ans[1]=mid;
                s=mid+1; // shrinking search space from left to get the last position
            }
            else if(nums[mid]<target) s=mid+1;
            else e=mid-1;
        }
        return ans;
    }
};
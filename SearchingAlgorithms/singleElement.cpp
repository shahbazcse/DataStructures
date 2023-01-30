// Link: https://leetcode.com/problems/single-element-in-a-sorted-array/

// Approach 1: Hashing [TC: O(N)]

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        unordered_map<int,int> m;
        for(auto i:nums) m[i]++;

        int ans=0;
        for(auto i:m){
            if(i.second==1) ans=i.first;
        }
        return ans;
    }
};

// Approach 2: Binary Search [TC: O(LogN)]

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int s=0;
        int e=nums.size()-1;
        int mid=s+(e-s)/2;
        int ans=0;
        
        while(s<=e){
            mid=s+(e-s)/2;

            if(mid%2!=0) mid--; // move mid to even index

            // check if both even and odd index pair are equal
            if(mid+1<nums.size() && nums[mid]==nums[mid+1]) s=mid+2; // move s to mid+2 to check next pair
            // if two distinct elements are present adjacent to each other, then num[mid] could be the single element
            else{
                ans=nums[mid]; // nums[mid] could be the answer, so update the ans
                e=mid-1; // move e to mid-1 to shrink search space from right, as we have found a potential answer at mid
            }
        }
        return ans; // return the last update answer
    }
};

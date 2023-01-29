// Link: https://leetcode.com/problems/shortest-unsorted-continuous-subarray/

// Approach: Using Two Pointers and Sorting [TC: O(NLogN)]

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int s=0;
        int e=nums.size()-1;

        vector<int> temp = nums;
        sort(temp.begin(),temp.end());

        int sIdx=-1;
        int eIdx=-1;

        while(s<=e){
            if(nums[s]==temp[s]) s++;
            else{
                sIdx=s;
                break;
            }
        }

        while(e>=0){
            if(nums[e]==temp[e]) e--;
            else{
                eIdx=e;
                break;
            }
        }

        int cnt=0;
        for(int i=sIdx; i<=eIdx; i++) cnt++;

        if(sIdx==-1 && eIdx==-1) return 0;
        else return cnt;
    }
};
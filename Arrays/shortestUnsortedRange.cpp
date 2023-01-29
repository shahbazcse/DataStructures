// Link: https://leetcode.com/problems/shortest-unsorted-continuous-subarray/

// Approach 1: Using Two Pointers and Sorting [TC: O(NLogN)]

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

// Approach 2: Using Two Pointers [TC: O(N) / SC: O(1)]

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int e=-1;
        int maxi=nums[0];

        for(int i=1; i<nums.size(); i++){
            if(maxi>nums[i]){ // the left value is greater then current value
                e=i; // mark that index with end
            }else maxi = nums[i];
        }

        int s=-1;
        int mini=nums[nums.size()-1];

        for(int i=nums.size()-2; i>=0; i--){
            if(mini<nums[i]){ // the right value is smaller then current value
                s=i; // mark that index with start
            }else mini = nums[i];
        }

        if(e==-1 && s==-1) return 0;
        else return e-s + 1;
    }
};
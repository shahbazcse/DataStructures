// Link: https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/

class Solution {
public:
    bool checkSorted(vector<int> &temp){
        for(int i=1; i<temp.size(); i++){
            if(temp[i]<temp[i-1]) return false;
        }
        return true;
    }
    bool check(vector<int>& nums) {
        int n=nums.size();
        vector<int> temp(n);
        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                temp[(i+k)%n]=nums[i];
            }
            bool check = checkSorted(temp);
            if(check) return true;
        }
        return false;
    }
};
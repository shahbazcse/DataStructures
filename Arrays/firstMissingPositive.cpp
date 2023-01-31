// Link: https://leetcode.com/problems/first-missing-positive/

// Approach 1: Hashing [TC: O(N) / SC: O(N)]

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int,int> m;
        int n=nums.size();
        for(int i=0; i<n; i++){
            if(nums[i]>0 && nums[i]<=n){
                m[nums[i]]++;
            }
        }

        for(int i=0; i<n; i++){
            if(!(m.count(i+1))) return i+1;
        }
        return n+1;
    }
};

// Approach 2: Swapping the elements [TC: O(N) / SC: O(1)]

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        
        for(int i=0; i<n; i++){
            int element=nums[i];

            if(element>0 && element<=n){
                int idx=element-1;
                if(nums[idx]!=element){
                    swap(nums[idx],nums[i]);
                    i--;
                }
            }
        }

        for(int i=0; i<n; i++){
            int element=nums[i];
            if(element!=i+1){
                return i+1;
            }
        }
        return n+1;
    }
};
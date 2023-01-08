// Link: https://leetcode.com/problems/3sum/

// Approach 1: Using 2 Pointer Approach [TC: O(N*N)]

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> ans; // Vector to store the triplets
        
        int k=0; // Target value
    
        sort(nums.begin(),nums.end()); // Sorting the array before applying Binary Search
        
        for(int i=0; i<nums.size(); i++){
            // Checking for duplicates
            if(i==0 || nums[i]!=nums[i-1] && i>0){
                // Key to search
                int key = k-nums[i];

                // Binary Search

                int s=i+1;
                int e=nums.size()-1;
            
                while(s<e){
                    if(nums[s]+nums[e]==key){

                        vector<int> temp; // Vector to store unique triplets

                        // Storing triplets
                        temp.push_back(nums[i]);
                        temp.push_back(nums[s]);
                        temp.push_back(nums[e]);

                        // Storing triplets in answer vector
                        ans.push_back(temp);
                        
                        while(s<e && nums[s]==nums[s+1]) s++; // Check and ignore duplicates from start pointer
                        while(s<e && nums[e]==nums[e-1]) e--; // Check and ignore duplicates from end pointer

                        // Moving ahead to check other possible unique triplets
                        s++;
                        e--;

                    }else if(nums[s]+nums[e]<key) s++;
                    else e--;
                }   
            }
        }
        return ans;
    }
};
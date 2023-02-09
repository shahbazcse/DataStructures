// Link: https://leetcode.com/problems/merge-sorted-array/

// Approach 1: [TC: O(MLogM) / SC: O(1)]
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k=0;
        for(int i=m; i<nums1.size(); i++){
                nums1[i] = nums2[k];
                k++;
        }
        sort(nums1.begin(),nums1.end());
    }
};

// Approach 2: [TC: O(M+N) / SC: O(M+N)]

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> ans;

        int i = 0;
        int j = 0;
        int k = 0;

        while(i<m && j<n){
            if(nums1[i] < nums2[j]){
                ans.push_back(nums1[i++]);
            }else{
                ans.push_back(nums2[j++]);
            }
        }

        while(i<m){
            ans.push_back(nums1[i++]);
        }

        while(j<n){
            ans.push_back(nums2[j++]);
        }

        nums1 = ans;
    }
};
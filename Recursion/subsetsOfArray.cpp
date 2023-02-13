// Link: https://leetcode.com/problems/subsets/

// Approach: Recursion [TC: O(2^N) / SC: O(N)]

class Solution {
public:
    void solve(vector<int> nums, vector<vector<int>> &ans, vector<int> &ds, int idx){
        if(idx==nums.size()){
            ans.push_back(ds);
            return;
        }

        ds.push_back(nums[idx]);
        solve(nums,ans,ds,idx+1);
        ds.pop_back();

        solve(nums,ans,ds,idx+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        
        solve(nums,ans,ds,0);

        return ans;
    }
};

// Link: https://practice.geeksforgeeks.org/problems/subsets-1613027340/1

// Approach: Recursion [TC: O(2^N) / SC: O(N)]
class Solution
{
    public:
    void solve(vector<int> A, vector<vector<int>> &ans, vector<int> &ds, int idx){
        if(idx==A.size()){
            ans.push_back(ds);
            return;
        }

        ds.push_back(A[idx]);
        solve(A,ans,ds,idx+1);
        ds.pop_back();

        solve(A,ans,ds,idx+1);
    }
    vector<vector<int> > subsets(vector<int>& A)
    {
        vector<vector<int>> ans;
        vector<int> ds;
        
        solve(A,ans,ds,0);
        
        sort(ans.begin(),ans.end()); // sort the subsets

        return ans;
    }
};
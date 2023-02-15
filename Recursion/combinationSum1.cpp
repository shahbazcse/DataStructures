// Link: https://leetcode.com/problems/combination-sum/

// Approach: [TC: O((2^Target)*K) / SC: O(K*X)]
// K is length of ans, X is number of combinations

class Solution {
public:
    void findCombination(int idx, vector<int> &candidates, int target, vector<int> &ds, vector<vector<int>> &ans){
        // Base condition
        if(idx==candidates.size()){
            if(target==0){
                ans.push_back(ds);
            }
            return;
        }
        // Take
        if(candidates[idx] <= target){
            ds.push_back(candidates[idx]);
            findCombination(idx,candidates,target-candidates[idx],ds,ans);
            ds.pop_back();
        }
        // Not-take
        findCombination(idx+1,candidates,target,ds,ans);

        return;
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        findCombination(0,candidates,target,ds,ans);
        return ans;
    }
};

// Link: https://practice.geeksforgeeks.org/problems/combination-sum-1587115620/1

// Approach: [TC: O((2^Target)*K) / SC: O(K*X)]
// K is length of ans, X is number of combinations

class Solution {
  public:
    void solve(vector<int> A, int B, vector<vector<int>> &ans, vector<int> &ds, int idx){
        if(idx==A.size()){
            if(B==0) ans.push_back(ds);
            return;
        }
        if(A[idx]<=B && A[idx]!=A[idx-1]){
            ds.push_back(A[idx]);
            solve(A,B-A[idx],ans,ds,idx);
            ds.pop_back();
        }
        solve(A,B,ans,ds,idx+1);
    }
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(A.begin(),A.end());
        solve(A,B,ans,ds,0);
        return ans;
    }
};
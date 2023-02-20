// Link: https://leetcode.com/problems/combination-sum-ii/

// Approach: [TC: O((2^N)*K) / SC: O(K*X)]
// N is number of unique elements, K is length of ans, X is number of combinations

class Solution {
public:
    void findUniqueCombination(int idx, vector<int>& arr, int target, vector<int> &ds, vector<vector<int>> &ans){
        if(target==0){
            ans.push_back(ds);
            return;
        }
        //Start from idx
        for(int i=idx; i<arr.size(); i++){
            if(i>idx && arr[i]==arr[i-1]) continue; // ignore duplicates
            if(arr[i]>target) break; // stop at elements bigger than target
            ds.push_back(arr[i]);
            findUniqueCombination(i+1,arr,target-arr[i],ds,ans);
            ds.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> ds;
        vector<vector<int>> ans;
        sort(candidates.begin(),candidates.end());
        findUniqueCombination(0,candidates,target,ds,ans);
        return ans;
    }
};

// Link: https://practice.geeksforgeeks.org/problems/combination-sum-ii/1

// Approach: [TC: O((2^N)*K) / SC: O(K*X)]
// N is number of unique elements, K is length of ans, X is number of combinations

class Solution {
  public:
    void solve(vector<int> arr, int target, vector<vector<int>> &ans, vector<int> &ds, int idx){
        if(target==0){
            ans.push_back(ds);
            return;
        }
        
        for(int i=idx; i<arr.size(); i++){
            if(i>idx && arr[i]==arr[i-1]) continue;
            if(arr[i]>target) break;
            ds.push_back(arr[i]);
            solve(arr,target-arr[i],ans,ds,i+1);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(candidates.begin(),candidates.end());
        solve(candidates,target,ans,ds,0);
        return ans;
    }
};
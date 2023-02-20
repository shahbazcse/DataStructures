// Link: https://leetcode.com/problems/combination-sum-iii/

// Approach: [TC: O(2^K) / SC: O(K)]

class Solution {
public:
    void solve(int k, int n, vector<vector<int>> &ans, vector<int> &ds, int num){
        if(k==0){
            if(n==0) ans.push_back(ds);
            return;
        }

        if(num>n) return;

        for(int i=num; i<=9; i++){
            ds.push_back(i);
            solve(k-1,n-i,ans,ds,i+1);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> ds;
        solve(k,n,ans,ds,1);
        return ans;
    }
};

// Link: https://practice.geeksforgeeks.org/problems/combination-sum-iii/1

// Approach: [TC: O(2^K) / SC: O(K)]

class Solution {
  public:
    void solve(int K, int N, vector<vector<int>> &ans, vector<int> &ds, int num){
        if(K==0){
            if(N==0){
                ans.push_back(ds);
            }
            return;
        }
        
        if(num>N) return;
        
        for(int i=num; i<=9; i++){
            ds.push_back(i);
            solve(K-1,N-i,ans,ds,i+1);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum(int K, int N) {
        vector<vector<int>> ans;
        vector<int> ds;
        solve(K,N,ans,ds,1);
        return ans;
    }
};
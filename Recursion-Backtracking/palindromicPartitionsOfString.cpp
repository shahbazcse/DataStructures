// Link: https://practice.geeksforgeeks.org/problems/find-all-possible-palindromic-partitions-of-a-string/1

// Approach: [TC: O(N*(2^N)) / SC: O(N*N)]

class Solution {
  public:
    bool isPalindrome(string S, int s, int e){
        while(s<=e){
            if(S[s++]!=S[e--]) return false;
        }
        return true;
    }
    void solve(string S, vector<vector<string>> &ans, vector<string> &ds, int idx){
        if(idx==S.length()){
            ans.push_back(ds);
            return;
        }
        
        for(int i=idx; i<S.length(); i++){
            if(isPalindrome(S,idx,i)){
                ds.push_back(S.substr(idx, i-idx+1));
                solve(S,ans,ds,i+1);
                ds.pop_back();
            }
        }
    }
    vector<vector<string>> allPalindromicPerms(string S) {
        vector<vector<string>> ans;
        vector<string> ds;
        
        solve(S,ans,ds,0);
        return ans;
    }
};
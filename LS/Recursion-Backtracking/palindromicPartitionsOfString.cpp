// Link: https://practice.geeksforgeeks.org/problems/find-all-possible-palindromic-partitions-of-a-string/1

// Approach: [TC: O(N*(2^N)) / SC: O(N*N)]

class Solution {
  public:
    bool isPalindrome(string str){
        int s=0;
        int e=str.length()-1;
        while(s<=e){
            if(str[s++]!=str[e--]) return false;
        }
        return true;
    }
    void solve(string S, vector<vector<string>> &ans, vector<string> ds, int idx){
        if(idx==S.length()){
            ans.push_back(ds);
            return;
        }
        
        for(int i=idx; i<S.length(); i++){
            if(isPalindrome(S.substr(idx,i-idx+1))){
                ds.push_back(S.substr(idx,i-idx+1));
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
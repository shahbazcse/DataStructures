// Link: https://practice.geeksforgeeks.org/problems/find-all-possible-palindromic-partitions-of-a-string/1

// Approach 1: Recursion + Backtracking [TC: O(N*(2^N)) / SC: O(N*N)]

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

// Approach 2: Recursion + Backtracking + Concatenating Strings [TC: O(N^2)) / SC: O(N^2)]

class Solution {
  public:
    bool isPalindrome(string str){
        int s = 0;
        int e = str.length()-1;
        
        while(s<=e){
            if(str[s++]!=str[e--]) return false;
        }
        return true;
    }
    void solve(string S, vector<vector<string>> &ans, vector<string> &ds, int idx){
        if(idx==S.size()){
            ans.push_back(ds);
            return;
        }
        
        string str;
        
        for(int i=idx; i<S.size(); i++){
            str += S[i]; // concatenate string
            if(isPalindrome(str)){
                ds.push_back(str);
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
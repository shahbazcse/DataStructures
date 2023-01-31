// Link: https://practice.geeksforgeeks.org/problems/string-subsequence-game5515/1

// Approach: Recursion [TC: O(2^N) / Aux SC:(2^N)]

class Solution {
  public:
    bool isConsonant(char ch){
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'){
            return false;
        }
        return true;
    }
    void findSubsequence(string S, set<string> &ans, string str, int idx){
        if(idx>=S.size()){
            if(str.size()>1 && isConsonant(str[0])==false && isConsonant(str[str.size()-1])==true){
                ans.insert(str);
            }
            return;
        }
        
        str.push_back(S[idx]);
        findSubsequence(S,ans,str,idx+1);
        str.pop_back();
    
        findSubsequence(S,ans,str,idx+1);
    }
    set<string> allPossibleSubsequences(string S) {
        set<string> ans;
        string str="";
        int idx=0;
        findSubsequence(S,ans,str,idx);
        return ans;
    }
};
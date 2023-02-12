// Link: https://practice.geeksforgeeks.org/problems/generate-all-possible-parentheses/1

// Approach: Recursion [TC: O((2^N)*N) / SC: O(2*N*X)]
// X is number of valid parenthesis

class Solution
{
    public:
    void generate(int open, int close, string str, vector<string> &ans){
        if(open==0 && close==0){
            ans.push_back(str);
            return;
        }
        
        if(open){
            // take 'open'
            str.push_back('(');
            generate(open-1,close,str,ans);
            str.pop_back(); // remove 'open' to further generate 'close' variation
        }
        
        if(close>open){
            // take 'close'
            str.push_back(')');
            generate(open,close-1,str,ans);
        }
    }
    vector<string> AllParenthesis(int n) 
    {
        vector<string> ans;
        string str;
        int open = n;
        int close = n;
        generate(open,close,str,ans);
        return ans;
    }
};
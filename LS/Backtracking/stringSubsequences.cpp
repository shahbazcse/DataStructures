// Link: https://practice.geeksforgeeks.org/problems/power-set4302/1

// Approach: Recursion + Backtracking [TC: O((2^N)*N) / SC: O((2^N)*N)]
// N is length of string s

class Solution{
	public:
	    void solve(string s, vector<string> &ans, string ds, int idx){
	        if(idx==s.length()){
	            if(!ds.empty()) ans.push_back(ds);
	            return;
	        }
	        
	        ds.push_back(s[idx]);
	        solve(s,ans,ds,idx+1);
	        ds.pop_back();
	        
	        solve(s,ans,ds,idx+1);
	    }
		vector<string> AllPossibleStrings(string s){
		    vector<string> ans;
		    string ds;
		    solve(s,ans,ds,0);
		    sort(ans.begin(),ans.end());
		    return ans;
		}
};
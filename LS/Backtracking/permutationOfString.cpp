// Link: https://practice.geeksforgeeks.org/problems/permutations-of-a-given-string2041/1

// Approach: Recursion + Backtracking +  swap() [TC: O(N! * N) / Aux. SC: O(!N)]

class Solution
{
	public:
	    void solve(string &S, vector<string> &ans, int idx){
	        if(idx==S.size()){
	            ans.push_back(S);
	            return;
	        }
	        
	        for(int i=idx; i<S.size(); i++){
	            if(S[i]==S[i+1]) continue; // ignore duplicates
	            swap(S[idx],S[i]);
	            solve(S,ans,idx+1);
	            swap(S[idx],S[i]);
	        }
	    }
		vector<string>find_permutation(string S)
		{
		    vector<string> ans;
		    
		    solve(S,ans,0);
		    
		    sort(ans.begin(),ans.end());
		    
		    return ans;
		}
};
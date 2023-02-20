// Link: https://practice.geeksforgeeks.org/problems/recursively-remove-all-adjacent-duplicates0744/1

// Approach: Recursion [TC: O(N^2) / SC: O(N^2)]

class Solution{
public:
    string removeDuplicates(string s){
        string res;
        int n=s.size();
        int i=0;
        
        while(i<n){
            if(i<n-1 && s[i]==s[i+1]){
                while(i<n-1 && s[i]==s[i+1]){
                    i++;
                }
            }else res.push_back(s[i]);
            
            i++;
        }
        return res;
    }
    
    void solve(string &s, string ans){
        // base case
        if(s.size()==ans.size()) return;
        
        ans = s;
        s = removeDuplicates(ans);
        
        // recursive call
        solve(s,ans);
    }
    
    string rremove(string s){
        string ans;
        
        solve(s,ans);
        
        return s;
    }
};
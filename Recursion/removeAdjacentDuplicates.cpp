// Link: https://practice.geeksforgeeks.org/problems/recursively-remove-all-adjacent-duplicates0744/1

// Approach: Recursion [TC: O(|S|) / SC: O(|S|)]

class Solution{
public:
    string helper(string s){
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
    
    string rremove(string s){
        string ans;
        
        while(s.size()!=ans.size()){
            ans=s;
            s=helper(ans);
        }
        
        return ans;
    }
};
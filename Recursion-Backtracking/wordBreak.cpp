// Link: https://practice.geeksforgeeks.org/problems/word-break-part-23249/1

// Approach: Recursion + Backtracking [TC: O((|S|)^2*N) / SC: O((|S|)^2)]
// |S| is length of string s, N is size of dictionary dict

class Solution{
public:
    void solve(vector<string> dict, string s, vector<string> &ans, string str, int idx){
       // store str word permutation after checking whole string s
       if(idx == s.size()){
           str.erase(str.begin()+str.length()-1); // remove extra space at end of str
           ans.push_back(str);
           return;
       }
       
       // check for every possible word permutations by doing different partitions in string s
       for(int i=idx; i<s.size(); i++){
           
           // partition string s based on i and idx, check if word found in dictionary
           string temp = s.substr(idx,i-idx+1);
           
           if(find(dict.begin(),dict.end(),temp) != dict.end()){
               
               // if word found, add a space and check for other words in string s in further recursive calls
               solve(dict,s,ans,str+temp+" ",i+1);
               
           }
           // backtrack and check for other possible permutations by doing different partitions in string s
       }
    }
    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        vector<string> ans;
        
        solve(dict,s,ans,"",0);
        
        return ans;
    }
};
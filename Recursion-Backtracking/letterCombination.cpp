// Link: https://practice.geeksforgeeks.org/problems/possible-words-from-phone-digits-1587115620/1

// Approach: [TC: O((4^N)*N) / Aux. SC: O(N)]

class Solution
{
    public:
    void solve(int a[], int N, vector<string> &ans, vector<string> keypad, string str, int idx){
        if(idx==N){
            ans.push_back(str);
            return;
        }
        // create permutations strings for inputs from a[], run upto the size of keypad number's string size
        for(int i=0; i<keypad[a[idx]].size(); i++){
            solve(a,N,ans,keypad,str+keypad[a[idx]][i],idx+1);
        }
    }
    vector<string> possibleWords(int a[], int N)
    {
        vector<string> ans;

        // create a keypad with string values
        vector<string> keypad = {"","1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz","*","0","#"};
    
        solve(a,N,ans,keypad,"",0);
        
        return ans;
    }
};
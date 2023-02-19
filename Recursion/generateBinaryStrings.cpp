// Link: https://practice.geeksforgeeks.org/problems/generate-all-binary-strings/1

// Approach: Recursion [TC: O(2^N) / SC: O(N)]

class Solution{
public:
    void solve(int num, string ds, int idx){
        if(idx==num){
        // print after generating a unique string
            cout<<ds<<" ";
            return;
        }
        
        // add 0 to string
        solve(num,ds+'0',idx+1);
        
        // skip if 1 is present at the end of string to avoid consecutive 1s
        if(ds.back()!='1'){
            // add 1 to string
            solve(num,ds+'1',idx+1);
        }
    }
    void generateBinaryStrings(int& num){
        solve(num,"",0);
    }
};

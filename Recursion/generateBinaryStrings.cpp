// Link: https://practice.geeksforgeeks.org/problems/generate-all-binary-strings/1

// Approach: Recursion [TC: O(2^N) / SC: O(N)]

class Solution{
public:
    void solve(int num, string ds, int idx){
        if(idx==num){
            cout<<ds<<" ";
            return;
        }
        
        solve(num,ds+'0',idx+1);
        
        if(ds.back()!='1'){
            solve(num,ds+'1',idx+1);
        }
    }
    void generateBinaryStrings(int& num){
        solve(num,"",0);
    }
};

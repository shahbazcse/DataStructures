// Link: https://practice.geeksforgeeks.org/problems/good-numbers4629/1

// Approach: Recursion [TC: O(N) / SC: O(1)]

class Solution {
  public:
    bool validNumber(int n, int D, int sum){
        if(n==0) return true;
        
        int digit = n%10;
        
        if(digit == D || digit <= sum) return false;
        
        if(sum==-1) sum=digit;
        else sum+=digit;
        
        validNumber(n/10,D,sum);
    }
    vector<int> goodNumbers(int L, int R, int D) {
        vector<int> ans;
        
        for(int i=L; i<=R; i++){
            if(validNumber(i,D,-1)){
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};
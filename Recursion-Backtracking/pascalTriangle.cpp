// Link: https://practice.geeksforgeeks.org/problems/pascal-triangle0652/1

// Approach: Recursion [TC: O(N^2) / SC: O(N^2)]

class Solution{
private:
    int m=1e9+7;
public:
    void solve(vector<ll> &ans, int n){
        //Base Case 
        if(n==1){
            ans[1]=1;
            return;
        }
        
        //Recursive call for previous row
        vector<ll>prev=nthRowOfPascalTriangle(n-1);
        
        //Forming nth row from previous row
        for(int i=1;i<n-1;i++){
            ans[i]= (prev[i] + prev[i-1])%m;//modulo
        }
        ans[n-1]=1;
    }
    vector<ll> nthRowOfPascalTriangle(int n) {
        vector<ll> ans(n);
        ans[0]=1;
        solve(ans,n);
        return ans;
    }
};
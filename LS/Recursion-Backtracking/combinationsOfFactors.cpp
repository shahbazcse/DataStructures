// Link: https://www.geeksforgeeks.org/print-combinations-factors-ways-factorize/

// Approach: Recursion [TC: O(N^2) / SC: O(N^2)]

#include <bits/stdc++.h>
using namespace std;

// Recursive function to find all factor combinations of n
void solve(int curr, int n, int product, vector<vector<int>> &ans, vector<int> &ds){
    
    // Base case: if curr is greater than n/2 or product is greater than n, return
    if(curr>n/2 || product>n){
        return;
    }
    
    // If product is equal to n, current combination is valid. Add to answer and return
    if(product == n){
        ans.push_back(ds);
        return;
    }
    
    // Include current factor in the current combination, and call solve recursively with updated arguments
    ds.push_back(curr);
    solve(curr,n,product*curr,ans,ds);
    ds.pop_back(); // Remove current factor from current combination
    
    // Call solve recursively with updated arguments
    solve(curr+1,n,product,ans,ds);
}

int main() {
    int n = 16;
    
    vector<vector<int>> ans; // Stores all valid factor combinations
    vector<int> ds; // Current combination of factors being processed
    
    solve(2, n, 1, ans, ds); // Call solve function with initial arguments
    
    // Print all valid factor combinations
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}

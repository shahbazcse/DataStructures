// Link: https://www.codingninjas.com/codestudio/problems/print-like-a-wave_893268

// Approach: [TC: O(N*M) / SC: O(N*M)]

#include <bits/stdc++.h> 
vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols)
{
    vector<int> ans;

    for(int col=0; col<mCols; col++){
        if(col%2==0){
            for(int row=0; row<nRows; row++){
                ans.push_back(arr[row][col]);
            }
        }else{
            for(int row=nRows-1; row>=0; row--){
                ans.push_back(arr[row][col]);
            }
        }
    }
    return ans;
}
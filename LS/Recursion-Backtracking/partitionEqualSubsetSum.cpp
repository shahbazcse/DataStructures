// Link: https://www.geeksforgeeks.org/all-possible-binary-numbers-of-length-n-with-equal-sum-in-both-halves/

// Approach: [TC: O(2^N) / SC: O(N)]
// N is the number of digits

#include <bits/stdc++.h>
using namespace std;

void solve(int n, string left, string right, int diff){
    // even length of string
    if(n==0){
        // if difference between sum of left and right halves is zero, then it means sum of both halves are equal
        if(diff==0) cout<<left+right<<" ";
        return;
    }
    
    // odd length of string
    if(n==1){
        // if difference between sum of left and right halves is zero, then it means sum of both halves are equal
        if(diff==0){
            // storing both combinations for 0 and 1 at middle
            cout<<left+"0"+right<<" ";
            cout<<left+"1"+right<<" ";
        }
        return;
    }
    
    if(2*abs(diff) <= n){
        // add 0 to both left and right halves, diff will remain same as sum is same
        solve(n-2,left+"0",right+"0",diff);
        // add 0 to left half and 1 to right half, sum will increase by 1 as 1 is added in right half, so diff will be reduced by 1
        solve(n-2,left+"0",right+"1",diff-1);
        // add 1 to left half and 0 to right half, sum will increase by 1 as 1 is added in left half, so diff will be increased by 1
        solve(n-2,left+"1",right+"0",diff+1);
        // add 1 to both left and right halves, sum will remain same
        solve(n-2,left+"1",right+"1",diff);
    }
}

int main() {
    int n=6;
    
    // to check the difference between sum of left and right halves
    int diff=0;
    
    // generating left half
    string left;
    
    // generating right half
    string right;
    
    solve(n,left,right,diff);

    return 0;
}

// Similar Question: https://leetcode.com/problems/partition-equal-subset-sum/
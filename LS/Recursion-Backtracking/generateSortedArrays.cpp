// Link: https://www.geeksforgeeks.org/generate-all-possible-sorted-arrays-from-alternate-elements-of-two-given-arrays/

// Approach: Recursion [TC: O(2^(M+N)) / SC: O(2^(M+N))]

#include<bits/stdc++.h>
using namespace std;

void solve(vector<int> A, vector<int> B, vector<int> &ds, int idx1, int idx2, bool flag){
    // include element from A
    if(flag){
        // print sorted arrays
        if(ds.size() != 0){
            for(auto it: ds) cout<<it<<" ";
            cout<<endl;
        }
        // Recursive calls for all elements of A
        for(int i=idx1; i<A.size(); i++){
            // inserting first element
            if(ds.size() == 0){
                ds.push_back(A[i]);
                solve(A,B,ds,i+1,idx2,!flag);
                ds.pop_back();
            }
            else{
                // check greater element of A and insert in ds
                if(A[i] > ds.back()){
                    ds.push_back(A[i]);
                    solve(A,B,ds,i+1,idx2,!flag);
                    ds.pop_back();
                }
            }
        }
    }
    // include element from B
    else{
        // Recursive calls for all elements of B
        for(int j=idx2; j<B.size(); j++){
            // check greater element of B and insert in ds
            if(B[j] > ds.back()){
                ds.push_back(B[j]);;
                solve(A,B,ds,idx1,j+1,!flag);
                ds.pop_back();
            }
        }
    }
}

int main() {
    vector<int> A = {10, 15, 25};
    vector<int> B = {5, 20, 30};
    vector<int> ds;
    
    int idx1 = 0;
    int idx2 = 0;
    
    // flag will be used to always include first element from A
    bool flag = true;
    
    solve(A,B,ds,idx1,idx2,flag);
    
    return 0;
}
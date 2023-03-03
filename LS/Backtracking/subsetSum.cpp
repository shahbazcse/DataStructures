// Link: https://www.geeksforgeeks.org/subset-sum-problem/

// Approach: Backtracking [TC: O(2^N) / SC: O(N)]

#include <bits/stdc++.h>
using namespace std;

int totalNodes=0;

void isSubsetSum(int n, vector<int> arr, int K, vector<int> &ds, int idx){
    totalNodes++;

    if(K==0){
        for(auto it: ds) cout<<it<<" ";
        cout<<endl;
        return;
    }
    
    for(int i=idx; i<n; i++){
        if(arr[i]<=K){
            ds.push_back(arr[i]);
            isSubsetSum(n, arr, K-arr[i],ds,i+1);
            ds.pop_back();
        }
    }
}

int main()
{
    vector<int> arr = {15, 22, 14, 26, 32, 9, 16, 8};

    sort(arr.begin(),arr.end());

    int target = 53;

    vector<int> ds;

    isSubsetSum(arr.size(),arr,target,ds,0);

    cout << "Nodes generated: " << totalNodes;

    return 0;
}
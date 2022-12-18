#include<bits/stdc++.h>
using namespace std;

// Problem: Print all the Subsequences in an Array

void printSubs(int idx, vector<int> &ds, int arr[], int size){
    // Base condition
    if(idx==size){
        for(auto it : ds) cout<<it;
        if(ds.size()==0) cout<<"{}";
        cout<<endl;
        return;
    }
    // Multiple recursive calls
    
    // Not-take condition, this element is not added to the subsequence
    printSubs(idx+1,ds,arr,size);

    // Take condition, this element is added to the subsequence
    ds.push_back(arr[idx]);
    printSubs(idx+1,ds,arr,size);
    ds.pop_back();
}

int main(){

    int arr[] = {3,1,2};

    // Vector to store subsequences
    vector<int> ds;
    
    int size = sizeof(arr)/sizeof(arr[0]);

    // Function call
    printSubs(0,ds,arr,size);

    return 0;
}
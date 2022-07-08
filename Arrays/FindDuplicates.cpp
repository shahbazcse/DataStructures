#include<iostream>
#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
int findDuplicate(vector<int> &arr) 
{
    for(int i=0; i<arr.size(); i++){
        for(int j=i+1; j<arr.size(); j++){
            if(arr[i]==arr[j]){
                cout<<arr[i]<<endl;
            }
        }
    }
}

// Optimized Approach
int findDuplicate(vector<int> &arr) 
{
    int ans=0;
    for(int i=0; i<arr.size(); i++){
        ans=ans^arr[i];
    }
    for(int j=1; j<arr.size(); j++){
        ans=ans^j;
    }
    return ans;
}
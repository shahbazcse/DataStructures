// Link: https://www.codingninjas.com/codestudio/problems/aggressive-cows_1082559

// Approach: Binary Search [TC: O(LogN)]

#include <bits/stdc++.h>
bool isPossible(vector<int> &stalls, int k, int mid){
    int cowCount=1;
    int lastPosition=stalls[0];
    
    for(int i=0; i<stalls.size(); i++){
        if(stalls[i]-lastPosition>=mid){
            cowCount++;
            if(cowCount==k){
                return true;
            }
            lastPosition=stalls[i];
        }
    }#include <bits/stdc++.h>
bool isPossible(vector<int> &stalls, int k, int mid){
    int cowCount=1;
    int lastPosition=stalls[0];
    
    for(int i=0; i<stalls.size(); i++){
        if(stalls[i]-lastPosition>=mid){
            cowCount++;
            if(cowCount==k){
                return true;
            }
            lastPosition=stalls[i];
        }
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{

    int s=0;
    int maxi=INT_MIN;
    int mini=INT_MAX;
    for(int i=0; i<stalls.size(); i++){
        maxi=max(maxi,stalls[i]);
        mini=min(mini,stalls[i]);
    }
    int e=maxi-mini;
    int mid=s-(e-s)/2;
    int ans=-1;
    
    while(s<=e){
        if(isPossible(stalls,k,mid)){
            ans=mid;
            s=mid+1;
        }else e=mid-1;
        mid=s+(e-s)/2;
    }
    return ans;
}
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(),stalls.end());
    int s=0;
    int maxi=INT_MIN;
    int mini=INT_MAX;
    for(int i=0; i<stalls.size(); i++){
        maxi=max(maxi,stalls[i]);
        mini=min(mini,stalls[i]);
    }
    int e=maxi-mini;
    int mid=s-(e-s)/2;
    int ans=-1;
    
    while(s<=e){
        if(isPossible(stalls,k,mid)){
            ans=mid;
            s=mid+1;
        }else e=mid-1;
        mid=s+(e-s)/2;
    }
    return ans;
}
// Link: https://practice.geeksforgeeks.org/problems/binary-search-1587115620/1

// Approach: Recursion [TC: O(LogN) / SC: O(1)]

class Solution {
  public:
    int helper(int arr[], int low, int high, int k){
        // base case
        if(low>high) return -1;
        
        int mid = low + (high - low)/2;
        
        if(arr[mid] == k) return mid;
        
        // recursive calls
        if(arr[mid] < k) helper(arr,mid+1,high,k);
        else helper(arr,low,mid-1,k);
    }
    
    int binarysearch(int arr[], int n, int k) {
        int low=0;
        int high=n-1;
        return helper(arr,low,high,k);
    }
};
// Link: https://practice.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/0

// Kadane's Algorithm [TC: O(N)]

class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n){
        
        long long int maxSum=INT_MIN;
        long long int sum=0;
        for(int i=0; i<n; i++){
            sum+=arr[i];
            maxSum=max(maxSum,sum);
            if(sum<0) sum=0;
        }
        return maxSum;
    }
};
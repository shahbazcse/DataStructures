// Link: https://practice.geeksforgeeks.org/problems/maximum-triplet-sum-in-array0129/1

// Approach 1: [TC: O(NlogN)]

class Solution{
    public:
    int maxTripletSum(int arr[], int n)
    {
    	sort(arr,arr+n);
    	
    	int maxSum=0;
    	int cnt=0;
    	for(int i=n-1; i>=0; i--){
    	    maxSum+=arr[i];
    	    cnt++;
    	    if(cnt==3) break;
    	}
    	return maxSum;
    }
};

// Approach 1: [TC: O(N)]

// Find max, 2nd max, and 3rd max elements, and return their sum
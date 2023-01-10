// Link: https://practice.geeksforgeeks.org/problems/max-sum-in-the-configuration/1

// Approach 1: Brute Force [TC: O(n^2)]

int max_sum(int A[],int N)
{
    int maxSum=INT_MIN;
    for(int i=0; i<N; i++){
    int sum=0;
        for(int j=0; j<N; j++){
            sum+=A[(j+i)%N]*j;
        }
        if(maxSum<sum) maxSum=sum;
    }
    return maxSum;
}

// Approach 2: 
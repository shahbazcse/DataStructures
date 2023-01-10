// Link: https://practice.geeksforgeeks.org/problems/max-sum-in-the-configuration/1

// Approach 1: Brute Force [TC: O(N^2)]

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

// Approach 2: [TC: O(N)]

int max_sum(int A[],int N)
{
    int arrSum=0;
    
    // Finding the sum of array
    for(int i=0; i<N; i++) arrSum+=A[i];
    
    int currSum=0;
    
    // Finding the sum of array in rotation from 0th position
    for(int i=0; i<N; i++) currSum+=i*A[i];
    
    int maxSum=currSum;
    
    /*
        To find the sum of all rotations from 1 to N-1 position in
        a single pass, we use previous rotation's sum to find the 
        next rotation's sum, and each time updating the maxSum.

        To find next rotation's sum, we have to tweak previous
        rotation's sum by adding and subtracting values based on
        patterns.

        E.g: When an array is rotated by one, following changes happen in sum of i*A[i]:
        1. Multiplier of A[i-1] changes from 0 to N-1, i.e., A[i-1] * (N-1) is added to 'currSum'.
        2. Multipliers of other terms is decremented by 1. i.e., (arrSum – A[i-1]) is 
           subtracted from 'currSum' where 'arrSum' is sum of all numbers.
    */
   
    // Finding the sum of array in rotation from 1 to N-1 positions
    for(int i=1; i<N; i++){
        int nextSum=currSum - (arrSum - A[i-1]) + A[i-1]*(N-1);
        maxSum=max(maxSum,nextSum); // Checking and storing greater value in maxSum
        currSum=nextSum;
    }
    return maxSum; // Returning maximum sum
}
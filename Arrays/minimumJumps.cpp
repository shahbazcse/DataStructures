// Link: https://www.codingninjas.com/codestudio/problems/minimum-jumps_1062693

int minimumJumps(vector<int> &arr, int n)
{
    int maxReach=arr[0]; // Initially maxReach will be equal to the value at 0th index
    int steps=arr[0]; // Initially steps will be equal to the value at 0th index
    int jumps=1; // Initially we can perform only one jump from 0th index
    
    if(n==1) return 0; // If array has only one element then no jumps are possible, so return 0
    if(arr[0]==0) return -1; // If the value at 0th index is 0, then 0 jumps are possible further, hence we will never reach the end of the array
    
    // Now we will check from 1st index to (n-1)th index
    for(int i=1; i<n; i++){
        if(i==n-1) return jumps; // If i reach to the end of array, then return all the total jumps taken
        maxReach=max(maxReach,i+arr[i]); // Check and store the max value between maxReach and i+arr[i], as it denotes the max number steps we can take further
        steps--; // We decrement steps as we move ahead in array
        // If steps are exhausted, then we have to take another jump
        if(steps==0){
            jumps++; // Since steps had exhausted, we will take another jump and increment 'jumps'
            if(i>=maxReach) return -1; // If ith index becomes greater than maxReach, it means our maxReach will never surpass the ith index and hence it will never reach the end of array
            steps=maxReach-i; // Now we again update the number of steps
        }
    }
}
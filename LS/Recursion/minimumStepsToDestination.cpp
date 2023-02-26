// Link: https://practice.geeksforgeeks.org/problems/minimum-number-of-steps-to-reach-a-given-number5234/1

// Approach 1: Recursion [TC: O(2^D) / SC: O(D)] - TLE

class Solution{
public:
    int solve(int D, int sum, int steps){
        // If the absolute value of the current position exceeds the target distance, 
        // return INT_MAX to indicate that the current path is invalid.
        if(abs(sum) > D) return INT_MAX;
        
        // If the current position equals the target distance,
        // return the number of steps taken so far to indicate that the current path is valid.
        if(sum == D) return steps;
        
        // Recursively call the solve function twice to simulate a forward jump and a backward jump.
        // Increment the number of steps taken by 1 in each call.
        int pos = solve(D,sum+steps+1,steps+1);
        int neg = solve(D,sum-steps-1,steps+1);
        
        // Return the minimum of the results from the two recursive calls,
        // which represents the minimum number of steps required to reach the target distance.
        return min(pos,neg);
    }
    
    // A helper function that calls the solve function with initial parameters.
    int minSteps(int D){
        return solve(D,0,0);
    }
};

// Approach 2: Iterative [TC: O(D) / SC: O(1)]

class Solution
{
public:
    int minSteps(int D) // A function that takes an integer D as input and returns an integer.
    {
        int target = abs(D); // Set target to the absolute value of D.
        int step = 0; // Initialize step to 0 to keep track of the number of steps taken.
        int sum = 0; // Initialize sum to 0 to keep track of the current position.
        
        // Loop until the sum is greater than or equal to the target.
        while(sum < target){
            step++; // Increment step by 1.
            sum += step; // Add step to sum.
        }
        
        // If the difference between the sum and target is odd, add one more step to make it even.
        while((sum-target)%2 != 0){
            step++; // Increment step by 1.
            sum+=step; // Add step to sum.
        }
        
        return step; // Return the final value of step.
    }
};
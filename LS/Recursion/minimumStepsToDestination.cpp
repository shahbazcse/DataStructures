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
    int minSteps(int D)
    {
        // Initialize the number of steps taken so far and the current position of the frog to zero.
        int steps = 0;
        int sum = 0;
        
        // Enter an infinite loop to simulate the frog jumping forward and backward.
        while(1){
            // Update the current position of the frog by adding the number of steps taken so far.
            sum += steps;
            
            // Increment the number of steps taken by 1.
            steps++;
            
            // Check if the frog has reached the target distance D.
            if(sum == D){
                // If so, return the number of steps taken so far minus 1 to represent the minimum number of steps required.
                return steps-1;
            }
            
            // Check if the frog has overshot the target distance D and can reach it by making equal forward and backward jumps.
            if(sum > D && (sum-D)%2 == 0){
                // If so, return the number of steps taken so far minus 1 to represent the minimum number of steps required.
                return steps-1;
            }
        }
        
        // This line of code is unreachable, but added to avoid a compiler warning.
        return 0;
    }
};
// Link: https://practice.geeksforgeeks.org/problems/count-ways-to-reach-the-nth-stair-1587115620/1

// Approach 1: Brute Force Recursion [TC: O(2^N) / SC: O(1)] - TLE ERROR

class Solution
{
    public:
    //Function to count number of ways to reach the nth stair.
    int mod = 1e9+7;
    void solve(int n, int idx, int &ways){
        if(idx>n) return;
        
        if(idx==n){
            ways++;
            return;
        }
        
        // for 1 step at once
        solve(n,idx+1,ways);
        
        // for 2 steps at once
        solve(n,idx+2,ways);
    }
    int countWays(int n)
    {
        int ways=0;
        solve(n,0,ways);
        return ways%mod;
    }
};

// Approach 2: Optimized Recursion [TC: O(N) / SC: O(1)]

class Solution
{
    public:
    int mod = 1e9+7;
    int solve(int n, int step1, int step2, int idx){
        if(idx>n) return step2; // step2 keeps count of total ways
        
        // move step1 by 1x and step2 by 2x
        solve(n,step2,(step1+step2)%mod,idx+1);
    }
    int countWays(int n)
    {
        return solve(n,1,1,2);
    }
};
// Link: https://practice.geeksforgeeks.org/problems/power-of-numbers-1587115620/1

// Approach: Recursion [TC: O(LogN) / SC: O(LogN)]

class Solution{
    public:
    #define mod 1000000007
    long long power(int N,int R)
    {
        if(R==0) return 1;
        
        long long ans = power(N,R/2);
        ans = (ans*ans)%mod;
        
        if(R%2 == 0) return ans;
        else return (ans*N)%mod;
    }

};
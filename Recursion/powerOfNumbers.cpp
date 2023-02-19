// Link: https://practice.geeksforgeeks.org/problems/power-of-numbers-1587115620/1

// Approach: Recursion [TC: O(LogN) / SC: O(LogN)]

/*
    This code is a recursive function that calculates the power of a number N to the power of R.
    It uses a divide and conquer approach to calculate the power.
    The function first checks if R is equal to 0, in which case it returns 1.
    It then calculates the power of N to the power of R/2 and stores it in the variable ans.
    It then multiplies ans by itself and takes the modulus of the result with the mod variable.
    If R is even, the function returns ans. If R is odd, the function returns the product of ans and N, taking the modulus of the result with the mod variable.
*/
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
// Link: https://practice.geeksforgeeks.org/problems/tower-of-hanoi-1587115621/1

// Approach: Recursion [TC: O(LogN(10base)) / SC: O(1)]

class Solution{
public:
    void solve(int N, int &sum){
        if(N==0) return;
        
        int digit = N%10;
        
        sum += digit;
        
        solve(N/10,sum);
    }
    int sumOfDigits(int N){
        int sum=0;
        solve(N,sum);
        return sum;
    }
};
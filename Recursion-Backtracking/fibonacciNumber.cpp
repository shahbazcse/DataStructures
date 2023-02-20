// Link: https://leetcode.com/problems/fibonacci-number/

// Approach: [TC: O(2^N) / SC: O(1)]

class Solution {
public:
    int fib(int n) {
        if(n<=1) return n;

        return fib(n-1) + fib(n-2); // adding last and second last values
    }
};
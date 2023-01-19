// Link: https://leetcode.com/problems/sqrtx/

// Approach: Binary Search [TC: O(LogN)]

class Solution {
public:
    int mySqrt(int x) {
        long long int s=0;
        long long int e=x;
        long long int mid=s+(e-s)/2;
        long long int closestDigit=-1;
        while(s<=e){
            long long int ans=mid*mid;
            if(ans==x) return mid;
            if(ans<x){
                closestDigit=mid;
                s=mid+1;
            }
            else e=mid-1;
            mid=s+(e-s)/2;
        }
        return closestDigit;
    }
};
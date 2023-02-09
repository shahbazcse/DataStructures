// Link: https://practice.geeksforgeeks.org/problems/lucky-numbers2911/1

// Approach: Recursion [TC: O(sqrt(N)) / SC: O(sqrt(N))]

class Solution{
public:
    int count=1;
    bool isLucky(int n) {
        count++;
        if(count>n) return true; // number is not deleted, hence lucky number
        if(n%count==0) return false; // number is deleted, hence not a lucky number
        return isLucky(n-(n/count));
    }
};
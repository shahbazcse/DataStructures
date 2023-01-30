// Link: https://practice.geeksforgeeks.org/problems/missing-number-in-array1416/1

// Approach 1: Brute Force [TC: O(N) / SC: O(1)]

class Solution{
  public:
    int MissingNumber(vector<int>& array, int n) {
        int sum=0;
        for(auto i:array) sum+=i;
        
        int totalSum=0;
        for(int i=1; i<=n; i++) totalSum+=i;
        
        return totalSum-sum;
    }
};

// Approach 2: XOR Operator [TC: O(N)]

class Solution{
  public:
    int MissingNumber(vector<int>& array, int n) {
        int ans=0;
        for(auto i:array) ans^=i;
        
        for(int i=1; i<=n; i++) ans^=i;
        
        return ans;
    }
};
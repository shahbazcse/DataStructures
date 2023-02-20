// Link: https://practice.geeksforgeeks.org/problems/check-if-there-exists-a-subsequence-with-sum-k/1

// Approach: Recursion [TC: O(N*K) / SC: O(N*K)]
// N is size of list and K is target

class Solution{
    public:
    bool solve(int n, vector<int> arr, int k, int idx, int sum){
        if(sum>k) return false;
        if(idx==n){
            if(sum==k) return true;
            else return false;
        }

        if(solve(n,arr,k,idx+1,sum+arr[idx])) return true;
        
        if(solve(n,arr,k,idx+1,sum)) return true;
        
        return false;
    }
    bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
        return solve(n,arr,k,0,0);
    }
};
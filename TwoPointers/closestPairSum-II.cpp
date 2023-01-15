// Link: https://practice.geeksforgeeks.org/problems/find-the-closest-pair-from-two-arrays4215/1

// Approach: 2 Pointers + Binary Search [TC: O(N)]

class Solution{
  public:
    vector<int> printClosest(int arr[], int brr[], int n, int m, int x) {
        vector<int> ans(1,0);
        int s=0;
        int e=m-1;
        int diff=INT_MAX;
        while(s<n && e>=0){
            int sum=arr[s]+brr[e];
            if(diff>abs(sum-x)){
                diff=abs(sum-x);
                ans={arr[s],brr[e]};
            }
            if(x<sum) e--;
            else s++;
        }
        return ans;
    }
};
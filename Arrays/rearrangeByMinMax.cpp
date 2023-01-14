// Link: https://practice.geeksforgeeks.org/problems/rearrange-the-array5802/1

// Approach 1: Two Pointer [TC: O(N)]

class Solution{
  public:
    void rearrangeArray(int arr[], int n) {
        vector<int> temp;
        int s=0;
        int e=n-1;
        sort(arr,arr+n);
        while(s<=e){
            temp.push_back(arr[s]);
            if(s==e) break;
            temp.push_back(arr[e]);
            s++;
            e--;
        }
        for(int i=0; i<n; i++) arr[i]=temp[i];
    }
};
// Link: https://practice.geeksforgeeks.org/problems/check-if-an-array-is-sorted0701/1

class Solution {
  public:
    bool arraySortedOrNot(int arr[], int n) {
        for(int i=0; i<n; i++){
            if(i+1<n && arr[i]>arr[i+1]) return 0;
        }
        return 1;
    }
};
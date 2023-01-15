// Link: https://practice.geeksforgeeks.org/problems/find-triplets-with-zero-sum/1

// Approach: Sorting + 2 Pointers + Binary Search [TC: O(N*N)]

class Solution{
  public:
    //Function to find triplets with zero sum.
    bool findTriplets(int arr[], int n)
    { 
        sort(arr,arr+n);
        for(int i=0; i<n; i++){
            int s=i+1;
            int e=n-1;
            while(s<e){
                if(arr[i]+arr[s]+arr[e]==0) return true;
                if(arr[i]+arr[s]+arr[e]<0) s++;
                else e--;
            }
        }
        return false;
    }
};
// Link: https://practice.geeksforgeeks.org/problems/triplet-sum-in-array-1587115621/1

// Approach: Sorting + 2 Pointers + Binary Search [TC: O(N*N)]

class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int A[], int n, int X)
    {
        sort(A,A+n); // Sorting
        for(int i=0; i<n; i++){
            // 2 Pointer - s,e
            int s=i+1;
            int e=n-1;
            // Binary Search
            while(s<e){
                if(A[i]+A[s]+A[e]==X) return true;
                if(A[i]+A[s]+A[e]<X) s++;
                else e--;
            }
        }
        return false;
    }
};
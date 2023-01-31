// Link: https://practice.geeksforgeeks.org/problems/reorganize-the-array4810/1

// Approach: [TC: O(N)]

int * Rearrange(int *arr,int n){
    int *res = new int[n];
    for(int i=0; i<n; i++) res[i]=-1;
    
    for(int i=0; i<n; i++){
        if(arr[i]>=0) res[arr[i]] = arr[i];
    }
    return res;
}
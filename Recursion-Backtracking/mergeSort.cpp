// Link: https://practice.geeksforgeeks.org/problems/merge-sort/1

// Approach: [TC: O(NLogN) / SC: O(N)]

class Solution
{
    public:
    void merge(int arr[], int l, int m, int r)
    {
        int len1 = m-l+1;
        int len2 = r-m;
        
        int *first = new int[len1];
        int *second = new int[len2];
        
        int idx=l;
        for(int i=0; i<len1; i++) first[i] = arr[idx++];
        
        idx=m+1;
        for(int i=0; i<len2; i++) second[i] = arr[idx++];
        
        idx=l;
        int i=0,j=0;
        while(i<len1 && j<len2){
            if(first[i]<second[j]){
                arr[idx++] = first[i++];
            }else{
                arr[idx++] = second[j++];
            }
        }
        
        while(i<len1){
            arr[idx++] = first[i++];            
        }
        
        while(j<len2){
            arr[idx++] = second[j++];
        }
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        if(l>=r) return;
        
        int m=l+(r-l)/2;
        
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        
        merge(arr,l,m,r);
    }
};
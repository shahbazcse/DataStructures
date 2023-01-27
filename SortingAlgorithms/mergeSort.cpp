// Link: https://practice.geeksforgeeks.org/problems/merge-sort/1

// Approach: Create new array and copy values [TC: O(nlogn)]

class Solution
{
    public:
    void merge(int arr[], int l, int m, int r)
    {
        int s=l;
        int mid=m;
        int e=r;
        
        // find length of left and right parts
        int len1=mid-s+1;
        int len2=e-mid;
        
        // create new arrays
        int *first = new int[len1];
        int *second = new int[len2];
        
        // copy values
        int idx=s;
        for(int i=0; i<len1; i++) first[i]=arr[idx++]; // left part
        
        idx=mid+1;
        for(int i=0; i<len2; i++) second[i]=arr[idx++]; // right part
        
        //merge two sorted array
        idx=s;
        int i=0,j=0;
        while(i<len1 && j<len2){
            if(first[i]<second[j]){
                arr[idx++]=first[i++];
            }else{
                arr[idx++]=second[j++];
            }
        }
        
        while(i<len1){
            arr[idx++]=first[i++];
        }
        
        while(j<len2){
            arr[idx++]=second[j++];
        }
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        int s=l;
        int e=r;
        int mid=s+(e-s)/2;
        
        // base condition
        if(s>=e) return;
        
        // recursive calls
        mergeSort(arr,s,mid); // sort left part
        mergeSort(arr,mid+1,e); // sort right part
        
        merge(arr,s,mid,e); // merge array after sorting
    }
};
/*
    Advantages:

    1. Merge Sort is not in-place, merging step requires extra space to 
       store the elements
    2. Merge sort is stable,  the order of elements with equal values 
       is preserved during the sort
    3. It is relatively efficient for sorting large datasets
    4. It is useful for external sorting, where the data being sorted 
       does not fit in memory
    5. Merge sort algorithm can be easily parallelized, which means it can 
       take advantage of multiple cores to sort the data more quickly
    
    Drawbacks:
    
    1. It is effecient for large datasets but it is slower for small datasets
    2. It requires an additional memory space of 0(n) for the temporary array
       Linked Lists can be used to overcome this drawback
    3. It requires more code to implement since we are dividing the array 
       into smaller subarrays and then merging the sorted subarrays back together
*/
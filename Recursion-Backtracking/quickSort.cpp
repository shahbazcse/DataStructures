// Link: https://practice.geeksforgeeks.org/problems/quick-sort/1

// Approach: Recursion [TC: O(NLogN) / SC: O(1)]

class Solution
{
    public:
    void quickSort(int arr[], int low, int high)
    {
        if(low>=high) return;
        
        int p = partition(arr,low,high);
        
        quickSort(arr,low,p-1);
        quickSort(arr,p+1,high);
    }
    
    public:
    int partition (int arr[], int low, int high)
    {
       int pivot = arr[low];
       
       int cnt=0;
       for(int i=low+1; i<=high; i++){
           if(arr[i]<=pivot) cnt++;
       }
       
       int pivotIndex = low+cnt;
       
       swap(arr[low],arr[pivotIndex]);
       
       int s=low, e=high;
       
       while(s<pivotIndex && e>pivotIndex){
           if(arr[s]<=pivot){
               s++;
           }else if(arr[e]>pivot){
               e--;
           }else swap(arr[s++],arr[e--]);
       }
       return pivotIndex;
    }
};
// Link: https://practice.geeksforgeeks.org/problems/quick-sort/1

// Approach: [TC: O(NLogN)]

class Solution
{
    public:
    int partition (int arr[], int low, int high)
    {
       int pivot=arr[low]; // select first element as pivot
       
       // count how many element are smaller than pivot
       int cnt=0;
       for(int i=low+1; i<=high; i++){
           if(arr[i]<=pivot) cnt++;
       }
       
       // right position of pivot found
       int pivotIndex=low+cnt;

       // swap pivot with (element at pivotIndex) to place pivot at right position
       swap(arr[low],arr[pivotIndex]);
       
       // Now sort left and right sub-array of pivot using 2 pointers
       int s=low, e=high;
       
       while(s<pivotIndex && e>pivotIndex){
           // move forward if element is less than/equal to pivot
           if(arr[s]<=pivot){
               s++;
           }
           // move back if element is greater than pivot
           else if(arr[e]>pivot){
               e--;
           }
           // swap if element at left sub-array is greater than element at right sub-array of the pivot
           else swap(arr[s++],arr[e--]);
       }
       return pivotIndex; // return position of pivot
    }
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        // base case
        if(low>=high) return;
        
        // create partition
        int p=partition(arr,low,high);

        // sort left part
        quickSort(arr,low,p-1);
        
        // sort right part
        quickSort(arr,p+1,high);
    }
};
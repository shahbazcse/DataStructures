// Link: https://practice.geeksforgeeks.org/problems/quick-sort/1

// Approach: [TC: Avg Case: O(NLogN), Worst Case: O(N^2)]

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

/*
    1. Quick Sort is 'stable' only when we use index values as parameters
       to sort the array, otherwise not.

    2. It is 'in-place' as it uses extra space only for storing recursive 
       function calls but not for manipulating the input.

    3. Why Quick Sort is preferred for Arrays?

        a. One of the main reasons for efficiency in quick sort is locality of reference, 
           which makes it easy for the computer system to access memory locations that are 
           near to each other, which is faster than memory locations scattered throughout 
           the memory which is the case in merge sort.

        b. Quick sort is an in-place sorting algorithm i.e. it does not require any extra space, 
           whereas Merge sort requires an additional linear space, which may be quite expensive. 
           In merge sort, the allocation and deallocation of the extra space increases the 
           running time of the algorithm.

        c. The most practical implementation of Quick sort uses a randomized version which has an 
           expected time complexity of O(NlogN). Although in the randomized version the worst case 
           is possible, but for a particular pattern (like sorted array) the worst case doesn’t occur, 
           and therefore the randomized quick sort works well in practice.

    4. Why Merge Sort is preferred for Linked List?

        a. Merge sort is preferred for linked list, the nodes may not be present at adjacent memory 
           locations, therefore Merge Sort is used.

        b. Unlike arrays, in linked lists, we can insert items in the middle in O(1) extra space and O(1) time 
           if we are given a reference/pointer to the previous node. Therefore, we can implement the merge 
           operation in the merge sort without using extra space.

        c. Quick Sort requires a lot of access to different memory locations. Therefore, the overhead increases 
           for quick sort. On the other hand, merge sort accesses data sequentially and the need for random access is low.
    
    5. Advantages: 
        a. It is a divide-and-conquer algorithm that makes it easier to solve problems.
        
        b. It is efficient on large data sets.
        
        c. It is a stable sort, meaning that if two elements have the same key, their 
           relative order will be preserved in the sorted output
        
        d. It has a low overhead, as it only requires a small amount of memory to function
    
    6. Disadvantages: 
        a. It has a worst-case time complexity of O(n^2), which occurs when the pivot is chosen poorly
        
        b. It is not a good choice for small data sets
        
        c. It can be sensitive to the choice of pivot
        
        d. It is not cache-efficient
*/
// Similar question: Kth Largest Element: Just return arr[size-K]

// Link: 

//Approach 1: Using sort() function [TC: O(NlogN)]

class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        sort(arr,arr+r+1);
        return arr[k-1];
    }
};

// Approach 2: Using Quick Sort

class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        // Implement quick sort here
        return arr[k-1];
    }
};
// Link: https://practice.geeksforgeeks.org/problems/bubble-sort/1

// Approach: [TC: O()]

// Bubble Sort is a stable and in-place sorting algorithm

class Solution
{
    public:
    void bubbleSort(int arr[], int n)
    {
        for(int i=0; i<n-1; i++){
            bool swapped=false;
            for(int j=0; j<n-i-1; j++){
                if(arr[j]>arr[j+1]){
                    swap(arr[j],arr[j+1]);
                    swapped=true;
                }
            }
            if(swapped==false) break; // list is already sorted
        }
    }
};
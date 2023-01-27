// Link: https://practice.geeksforgeeks.org/problems/insertion-sort/1

// Approach: [TC: O(N^2)]

class Solution
{
    public:
    void insert(int arr[], int i)
    {
        int temp=arr[i];
        int j=i-1; // iterate backwards from i-1 till 0th index
        while(j>=0){
            if(arr[j]>temp) arr[j+1]=arr[j]; // right shift
            else break; // element smaller than 'temp' found, so break loop
            j--;
        }
        arr[j+1]=temp; // place 'temp' next to the smaller element
    }
    public:
    void insertionSort(int arr[], int n)
    {
        int i=1; // First element is assumed to be the smallest at beginning
        while(i<n){
            insert(arr,i);
            i++;
        }
    }
};
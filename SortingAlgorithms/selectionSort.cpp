// Link: https://practice.geeksforgeeks.org/problems/selection-sort/1

// Approach: [TC: O(N^2)]

class Solution
{
    public:
    int select(int arr[], int i, int n)
    {
        int min=i;
        for(int j=i+1; j<n; j++){
            if(arr[min]>arr[j]){
                min=j;
            }
        }
        swap(arr[min],arr[i]);
    }
     
    void selectionSort(int arr[], int n)
    {
        for(int i=0; i<n-1; i++){
            select(arr,i,n);
        }
    }
};
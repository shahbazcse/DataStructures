// Link: https://practice.geeksforgeeks.org/problems/largest-element-in-array4009/1

class Solution
{
public:
    int largest(vector<int> &arr, int n)
    {
        int max=0;
        for(int i=0; i<n; i++){
            if(max<arr[i])
                max=arr[i];
        }
        return max;
    }
};
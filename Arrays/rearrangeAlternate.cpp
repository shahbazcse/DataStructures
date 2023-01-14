// Link: https://practice.geeksforgeeks.org/problems/-rearrange-array-alternately-1587115620/1

// Approach: Two Pointer Approach [TC: O(N)]

class Solution{
    public:
    // This function wants you to modify the given input
    // array and no need to return anything
    // arr: input array
    // n: size of array
    //Function to rearrange  the array elements alternately.
    void rearrange(long long *arr, int n) 
    { 
    	vector<long long int >temp;
        
        int s=0;
        int e=n-1;
        
        while(s<=e){
            temp.push_back(arr[e]);
            temp.push_back(arr[s]);
            s++;
            e--;
            if(s==e) temp.push_back(arr[s]);
        }
        for(int i=0; i<n; i++) arr[i]=temp[i];
    }
};
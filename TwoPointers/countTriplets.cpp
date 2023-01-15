// Link: https://practice.geeksforgeeks.org/problems/count-the-triplets4615/1

// Approach: Sort + Reverse + 2 Pointers + Binary Search [TC: O(N*N)]

class Solution{
public:	
	
	int countTriplet(int arr[], int n)
	{
	    int cnt=0;
	    sort(arr,arr+n); // Sort
	    reverse(arr,arr+n); // Reverse
	    for(int i=0; i<n; i++){
            // 2 Pointer - s,e
	        int s=i+1;
	        int e=n-1;
            // Binary Search
	        while(s<e){
	            if(arr[s]+arr[e]==arr[i]) cnt++;
	            if(arr[s]+arr[e]<arr[i]) e--;
	            else s++;
	        }
	    }
	    return cnt;
	}
};
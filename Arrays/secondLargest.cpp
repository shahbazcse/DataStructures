// Link: https://practice.geeksforgeeks.org/problems/second-largest3735/1

class Solution{
public:	
	// Function returns the second
	// largest elements
	int print2largest(int arr[], int n) {
	    if(n==1) return -1;
        int max=arr[0];
        int max2=-1;
        for(int i=0; i<n; i++){
            if(max<arr[i]){
                max2=max;
                max=arr[i];
            }else{
                if(max2<arr[i] && arr[i]!=max) max2=arr[i];
            }
        }
        return max2;
	}
};
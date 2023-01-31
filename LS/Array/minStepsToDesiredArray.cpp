// Link: https://practice.geeksforgeeks.org/problems/minimum-steps-to-get-desired-array5519/1

class Solution{   
public:
    int countMinOperations(int arr[], int n) {
        int cnt=0;
        sort(arr,arr+n);
        while(true){
            for(int i=n-1; i>=0; i--){
                // Odd number
                if(arr[i]%2!=0){
                    arr[i]=arr[i]-1;
                    cnt++;
                }
                // Even number
                arr[i]=arr[i]/2;
            }
            if(arr[n-1]==0) break;
            cnt++;
        }
        return cnt;
    }
};
// Link: https://www.codingninjas.com/codestudio/problems/search-in-rotated-sorted-array_1082554

// Approach: [TC: O(LogN)]

int getPivot(vector<int> &arr, int n){
    int s=0;
    int e=n-1;
    int mid=s+(e-s)/2;
    
    while(s<e){
        if(arr[mid]>=arr[0]) s= mid+1;
        else e=mid;
        mid=s+(e-s)/2;
    }
    return s;
}

int binarySearch(vector<int> &arr, int start, int end, int key){
    int s=start;
    int e=end;
    int mid=s+(e-s)/2;
    
    while(s<=e){
        if(arr[mid]==key) return mid;
        if(key>arr[mid]) s=mid+1;
        else e=mid-1;
        mid=s+(e-s)/2;
    }
    return -1;
}

int findPosition(vector<int>& arr, int n, int k)
{   
    int pivot=getPivot(arr,n);
    
    if(arr[pivot]<=k && k<=arr[n-1]){
        return binarySearch(arr,pivot,n-1,k);
    }else{
        return binarySearch(arr,0,pivot-1,k);
    }
}
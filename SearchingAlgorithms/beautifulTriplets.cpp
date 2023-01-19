// Link: https://www.hackerrank.com/challenges/beautiful-triplets/problem?isFullScreen=true

// Approach: Binary Search [TC: O(N)]

bool binarySearch(vector<int> &arr,int k){
    int s=0;
    int e=arr.size()-1;
    int mid=s+(e-s)/2;
    
    while(s<=e){
        if(arr[mid]==k) return true;
        if(arr[mid]<k) s=mid+1;
        else e=mid-1;
        mid=s+(e-s)/2;
    }
    return false;
}

int beautifulTriplets(int d, vector<int> arr) {
    int cnt=0;
    
    for(int i=0; i<arr.size(); i++){
        if(binarySearch(arr,arr[i]) && binarySearch(arr,arr[i]+d) && binarySearch(arr,arr[i]+(d*2))){
            cnt++;
        }
    }
    return cnt;
}
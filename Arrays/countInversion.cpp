// Link: https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1

// Approach: Using Merge Sort [TC: O(NLogN) / SC:O(N)]

class Solution{
  public:
    long long int merge(long long arr[], long long l, long long m, long long r){
        long long s=l;
        long long e=r;
        long long mid=m;
        
        long long cnt=0;
        
        //find length
        long long len1=mid-s+1;
        long long len2=e-mid;
        
        //create new array
        long* first = new long[len1];
        long* second = new long[len2];
        
        //copy values
        long long idx=s;
        for(int i=0; i<len1; i++) first[i]=arr[idx++];
        
        idx=mid+1;
        for(int i=0; i<len2; i++) second[i]=arr[idx++];
        
        //merge two array
        idx=s;
        long i=0,j=0;
        while(i<len1 && j<len2){
            if(first[i] <= second[j]){
                arr[idx++] = first[i++];
            }else{
                arr[idx++] = second[j++];
                cnt+=len1-i;
                /*
                    Here, first[i] > second[j], so there are (len1 – i) inversions because left and right subarrays are sorted, 
                    so all the remaining elements in left-subarray (first[i+1], first[i+2] … first[len1-1]) will be greater than second[j]
                */
            }
        }
        
        while(i<len1){
            arr[idx++] = first[i++];
        }
        
        while(j<len2){
            arr[idx++] = second[j++];
        }
        
        return cnt;
    }
    
    long long int mergeSort(long long arr[], long long l, long long r){
        long long s=l;
        long long e=r;
        long long mid= s+(e-s)/2;
        
        if(s>=e) return 0;
        
        long long cnt=0;
        
        cnt += mergeSort(arr,s,mid);
        cnt += mergeSort(arr,mid+1,e);
        
        cnt += merge(arr,s,mid,e);
        
        return cnt;
    }
    
    long long int inversionCount(long long arr[], long long N)
    {
        return mergeSort(arr,0,N-1);
    }
};
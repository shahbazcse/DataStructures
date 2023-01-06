// Link: https://practice.geeksforgeeks.org/problems/find-all-pairs-whose-sum-is-x5808/1

// Approach 1: Brute Force [TC: N*M]
class Solution{
    public:
    vector<pair<int,int>> allPairs(int A[], int B[], int N, int M, int X)
    {
        vector<pair<int,int>> ans;
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(A[i]+B[j]==X) ans.push_back({A[i],B[j]});
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};

// Approach 2: Binary Search [TC: NLogN]

class Solution{
    public:
    // Binary Search
    bool isPair(int low, int high, int key, int B[]){
        while(low<=high){
            int mid=low+(high-low)/2;
            if(B[mid]==key) return true;
            else if(B[mid]<key) low=mid+1;
                 else high=mid-1;
        }
        return false;
    }
    vector<pair<int,int>> allPairs(int A[], int B[], int N, int M, int X)
    {
        sort(A,A+N);
        sort(B,B+M);
        
        vector<pair<int,int>> ans;
        
        for(int i=0; i<N; i++){
            if(isPair(0,M-1,X-A[i],B)) ans.push_back({A[i],X-A[i]});
        }
        return ans;
    }
};
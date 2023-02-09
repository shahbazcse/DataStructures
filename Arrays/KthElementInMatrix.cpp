// Link: https://practice.geeksforgeeks.org/problems/kth-element-in-matrix/1

// Approach 1: Brute Force [TC: O(N^2) / SC: O(N^2)]

int kthSmallest(int mat[MAX][MAX], int n, int k)
{
  vector<int> ds;

  for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
          ds.push_back(mat[i][j]);
      }
  }
  
  sort(ds.begin(),ds.end());
  
  return ds[k-1];
}

// Approach 2: Priority Queue - Min Heap [TC: O(K*LogK) / SC: O(k)]

int kthSmallest(int mat[MAX][MAX], int n, int k)
{
    int ans=0;
    priority_queue<vector<int>, vector<vector<int>>, greater<>> minHeap;
    
    for(int i=0; i<min(k,n); i++){
        minHeap.push({mat[i][0],i,0});
    }
    
    for(int i=1; i<=k; i++){
        auto top = minHeap.top();
        minHeap.pop();
        
        int r = top[1];
        int c = top[2];
        
        ans = top[0];
        
        if(c+1 < n){
            minHeap.push({mat[r][c+1],r,c+1});
        }
    }
    return ans;
}

// Approach 3: Binary Search [TC: O(D*(N*LogN)) / SC: O(1)]
// D is the log of absolute difference between minimum elment(mat[0][0]) and maximum element(mat[n-1][n-1])

int helper(int mat[MAX][MAX], int n, int num){
    int ans = 0;
    
    for(int i=0; i<n; i++){
        int low = 0;
        int high = n-1;
        
        while(low <= high){
            int mid=low+(high-low)/2;
            
            if(mat[i][mid]<=num){
                low = mid+1;
            }else high = mid-1;
        }
        ans+=low;
    }
    
    return ans;
}

int kthSmallest(int mat[MAX][MAX], int n, int k)
{
    int low = mat[0][0];
    int high = mat[n-1][n-1];
    
    while(low <= high){
        int mid = low + (high-low)/2;

        int count = helper(mat,n,mid);
        
        if(count<k){
            low=mid+1;
        }else high = mid-1;
    }
    return low;
}
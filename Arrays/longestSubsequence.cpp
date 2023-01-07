// Link: https://practice.geeksforgeeks.org/problems/longest-consecutive-subsequence2449/0

class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
      vector<int> ds;
      for(int i=0; i<N; i++) ds.push_back(arr[i]);
      sort(ds.begin(),ds.end());
      int maxCnt=0;
      int cnt=0;
      for(int i=0; i<N; i++){
          if(ds[i]==ds[i+1]-1 && i+1<N){
              cnt++;
              if(maxCnt<cnt) maxCnt=cnt;
          }else if(ds[i]==ds[i+1]) continue;
                else cnt=0; 
      }
      return maxCnt+1;
    }
};
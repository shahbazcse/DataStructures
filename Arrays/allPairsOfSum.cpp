// Link: https://practice.geeksforgeeks.org/problems/find-all-pairs-whose-sum-is-x5808/1

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
// Link: 

// Approach: [TC: O() / SC: O()]

class Solution
{
public:
    void findSubsets(int idx, vector<int> &arr, int N, vector<int> &ans, int sum){
        if(idx==N){
            ans.push_back(sum);
            return;
        }
        
        // Take
        findSubsets(idx+1,arr,N,ans,sum+arr[idx]);
        
        // Not take
        findSubsets(idx+1,arr,N,ans,sum);
        
        return;
    }
public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> ans;
        int sum=0;
        
        findSubsets(0,arr,N,ans,sum);
        sort(arr.begin(), arr.end());
        return ans;
    }
};
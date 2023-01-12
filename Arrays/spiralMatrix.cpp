// Link: https://practice.geeksforgeeks.org/problems/cd61add036272faa69c6814e34aa7007d5a25aa6/1

// Approach: [TC: O(N*M)]

class Solution{
	public:
	int findK(vector<vector<int>> &a, int n, int m, int k)
    {
        vector<int> ans;
        
        int top=0;
        int bottom=n-1;
        int left=0;
        int right=m-1;
        
        while(top<=bottom && left<=right){
            for(int i=left; i<=right; i++){
                ans.push_back(a[top][i]);
            }
            top++;
            for(int i=top; i<=bottom; i++){
                ans.push_back(a[i][right]);
            }
            right--;
            if(top<bottom){
                for(int i=right; i>=left; i--){
                    ans.push_back(a[bottom][i]);
                }
                bottom--;
            }
            if(left<right){
                for(int i=bottom; i>=top; i--){
                    ans.push_back(a[i][left]);
                }
                left++;
            }
        }
        return ans[k-1];
    }

};
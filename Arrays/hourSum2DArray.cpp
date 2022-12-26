// Problem: Hour Glass problem from HackerRank
int getMaxSum(int i, int j, int &maxSum, int ans, vector<vector<int>> arr) {
    if(i>3 || j>3){
        if(maxSum<ans){
            maxSum=ans;
        }
        return 0;
    }
    getMaxSum(i+1,j,maxSum,ans,arr);
    ans=arr[i][j]+arr[i][j+1]+arr[i][j+2]+arr[i+1][j+1]+arr[i+2][j]+arr[i+2][j+1]+arr[i+2][j+2];
    getMaxSum(i,j+1,maxSum,ans,arr);
    return maxSum;
}

int hourglassSum(vector<vector<int>> arr) {
    int maxSum=-9999;
    int ans=0;
    int i=0;
    int j=0;
    getMaxSum(i+1,j,maxSum,ans,arr);
    return maxSum;
}
// Link: https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

// Approach: Recursion + Backtracking [TC: O(4^(N*N)) / SC: O(N*N)]

class Solution{
    public:
    void solve(vector<vector<int>> m, int n, vector<string> &ans, string ds, int row, int col){
        // check row and col valid range in maze
        if(col<0 || col>=n || row<0 || row>=n || m[row][col]==0){
            return;
        }
        
        // store a solution upon reaching the exit
        if(col==n-1 && row==n-1){
            ans.push_back(ds);
            return;
        }
        
        // mark as visited, so block the path
        m[row][col] = 0;
        
        // left
        solve(m,n,ans,ds+'L',row,col-1);
        
        // right
        solve(m,n,ans,ds+'R',row,col+1);
        
        // up
        solve(m,n,ans,ds+'U',row-1,col);
        
        // down
        solve(m,n,ans,ds+'D',row+1,col);
        
        // mark as not visited, so unblock the path
        m[row][col] = 1;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        string ds;

        // check if exit is blocked
        if(m[n-1][n-1] == 0){
            ans.push_back("-1");
            return ans;
        }

        //check if entry is unblocked
        if(m[0][0] == 1) solve(m,n,ans,ds,0,0);

        return ans;
    }
};
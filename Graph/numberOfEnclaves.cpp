// Link: https://practice.geeksforgeeks.org/problems/number-of-enclaves/1

// Approach: DFS + Hashing [TC: O(N*M) / SC: O(N*M)]

class Solution {
  public:
    void dfs(vector<vector<int>> &grid, vector<vector<int>> &vis, int r, int c){
        vis[r][c] = 1;
        
        int n = grid.size();
        int m = grid[0].size();
        
        int delRow[] = {0,-1,0,+1};
        int delCol[] = {-1,0,+1,0};
        for(int i=0; i<4; i++){
            int nrow = r + delRow[i];
            int ncol = c + delCol[i];
            
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]==1){
                dfs(grid,vis,nrow,ncol);
            }
        }
    }
    int numberOfEnclaves(vector<vector<int>> &grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        for(int col=0; col<m; col++){
            // first row
            if(grid[0][col]==1 && !vis[0][col]){
                dfs(grid,vis,0,col);
            }
            // last row
            if(grid[n-1][col]==1 && !vis[n-1][col]){
                dfs(grid,vis,n-1,col);
            }
        }
        
        for(int row=0; row<n; row++){
            // first column
            if(grid[row][0]==1 && !vis[row][0]){
                dfs(grid,vis,row,0);
            }
            // last column
            if(grid[row][m-1]==1 && !vis[row][m-1]){
                dfs(grid,vis,row,m-1);
            }
        }
        
        int cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && grid[i][j]==1){
                    cnt++;
                }
            }
        }
        
        return cnt;
    }
};
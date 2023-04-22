// Link: https://practice.geeksforgeeks.org/problems/replace-os-with-xs0052/1

// Approach: DFS Traversal + Hashing [TC: O(N*M) / SC: O(N*M)]

class Solution{
public:
    void dfs(int r, int c, vector<vector<int>> &vis, vector<vector<char>> mat){
        vis[r][c] = 1;
        
        int n = mat.size();
        int m = mat[0].size();
        
        int delRow[] = {0,-1,0,+1};
        int delCol[] = {-1,0,+1,0};
        
        // move in all 4 directions
        for(int i=0; i<4; i++){
            int nrow = r + delRow[i];
            int ncol = c + delCol[i];

            // check for cell validity and mark all the 0's that are part of the boundary component as visited as they can never be surrounded by X
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && mat[nrow][ncol]=='O'){
                dfs(nrow,ncol,vis,mat);
            }
        }
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        // make dfs call for all the 0's at first and last row boundary, and mark the entire component as visited
        for(int col=0; col<m; col++){
            // first row
            if(!vis[0][col] && mat[0][col]=='O'){
                dfs(0,col,vis,mat);
            }
            // last row
            if(!vis[n-1][col] && mat[n-1][col]=='O'){
                dfs(n-1,col,vis,mat);
            }
        }
        // make dfs call for all the 0's at first and last column boundary, and mark the entire component as visited        
        for(int row=0; row<n; row++){
            // first column
            if(!vis[row][0] && mat[row][0]=='O'){
                dfs(row,0,vis,mat);
            }
            // last column
            if(!vis[row][m-1] && mat[row][m-1]=='O'){
                dfs(row,m-1,vis,mat);
            }
        }
        
        // check for all the 0's inside the matrix boundary surrounded by X and replace them with X
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && mat[i][j]=='O'){
                    mat[i][j]='X';
                }
            }
        }
        
        return mat;
    }
};
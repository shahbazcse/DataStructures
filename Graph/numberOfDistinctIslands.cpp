// Link: https://practice.geeksforgeeks.org/problems/number-of-distinct-islands/1

// Approach: DFS Traversal + Hashing [TC: O(N*M) / SC: O(N*M)]

class Solution {
  public:
    void dfs(int r, int c, vector<vector<int>> &grid, vector<vector<int>> &vis, vector<pair<int,int>> &temp, int row0, int col0){
        vis[r][c] = 1;
        
        // current cell coordinates will be subtracted from the base cell coordinates to get the frequency of the identical islands, if it exists
        temp.push_back({r-row0,c-col0});
        
        int n = grid.size();
        int m = grid[0].size();
        
        int delRow[] = {0,-1,0,+1};
        int delCol[] = {-1,0,+1,0};
        
        //  move in all 4 directions
        for(int i=0; i<4; i++){
            int nrow = r + delRow[i];
            int ncol = c + delCol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]==1){
                dfs(nrow,ncol,grid,vis,temp,row0,col0);
            }
        }
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        // keep track of the visited cells
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        // keep track of identical islands
        set<vector<pair<int,int>>> st;
        
        // DFS Traversal
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && grid[i][j]==1){
                    // list will store the coordinates of the land cell wrt to the base cell(cell from which dfs started i.e. i,j)
                    vector<pair<int,int>> temp;
                    
                    dfs(i,j,grid,vis,temp,i,j);

                    // list will be stored in the set, identical islands will increase frequency of previously visited identical island, whereas set size will indicate unique number of islands
                    st.insert(temp);
                }
            }
        }
        // set size will indicate unique number of islands
        return st.size();
    }
};
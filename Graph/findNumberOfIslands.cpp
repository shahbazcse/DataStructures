// Link: https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1

// Approach: BFS + Hashing [TC: O(N*M) / SC: O(N*M)]

class Solution {
  public:
    // BFS Traversal (can also be solved using DFS Traversal)
    void bfs(vector<vector<char>> grid, vector<vector<int>> &vis, int row, int col){
        vis[row][col] = 1;
        
        // queue to store coordinates of the cells depicting land
        queue<pair<int,int>> q;
        q.push({row,col});
        
        int n = grid.size();
        int m = grid[0].size();
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            // Checking neighbours in all 8 direction from the current cell
            for(int delRow=-1; delRow<=1; delRow++){
                for(int delCol=-1; delCol<=1; delCol++){
                    
                    int nRow = row + delRow;
                    int nCol = col + delCol;
                    
                    // checking whether neighbour lies within the grid boundary, and whether the neighbour is a land, and whether it is not visited
                    if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && grid[nRow][nCol] == '1' && !vis[nRow][nCol]){
                        q.push({nRow,nCol}); // if all checks are valid, push the neighbour in queue
                        vis[nRow][nCol] = 1; // mark the neighbour visited
                    }
                }
            }
        }
    }
  
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        // 2D hash array to keep track of visited nodes
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        // count the number of islands
        int cnt=0;
        
        // Perform BFS for every valid node as starting node untill all nodes are visited
        for(int row=0; row<n; row++){
            for(int col=0; col<m; col++){
                if(grid[row][col] == '1' && !vis[row][col]){
                    bfs(grid,vis,row,col);
                    cnt++;
                }
            }
        }
        
        return cnt;
    }
};
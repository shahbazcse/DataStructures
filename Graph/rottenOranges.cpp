// Link: https://practice.geeksforgeeks.org/problems/rotten-oranges2536/1

// Approach: BFS Traversal + Hashing [TC: O(R*C) / SC: O(R*C)]

class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        int ans = 0;
        
        int n = grid.size();
        int m = grid[0].size();
        
        // queue: {{row,col},time}
        queue<pair<pair<int,int>,int>> q;
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        int cntFresh = 0;
        
        for(int r=0; r<n; r++){
            for(int c=0; c<m; c++){
                if(grid[r][c]==2){
                    vis[r][c] = 2;
                    q.push({{r,c},0});
                }else vis[r][c] = 0;
                
                if(grid[r][c]==1) cntFresh++;
            }
        }
        
        int delRow[] = {-1,0,+1,0};
        int delCol[] = {0,+1,0,-1};
        
        int cnt=0;
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;
            q.pop();
            
            ans = max(ans,t);
            
            for(int i=0; i<4; i++){
                    int nrow = row + delRow[i];
                    int ncol = col + delCol[i];
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && vis[nrow][ncol]!=2){
                        vis[nrow][ncol] = 2;
                        q.push({{nrow,ncol},t+1});
                        cnt++;
                    }
            }
        }
        
        if(cnt!=cntFresh) return -1;
        
        return ans;
    }
};
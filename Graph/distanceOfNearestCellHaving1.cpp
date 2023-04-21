// Link: https://practice.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1

// Approach: BFS Traversal + Queue + Hashing [TC: O(N*M) / SC: O(N*M)]

class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    int n = grid.size();
	    int m = grid[0].size();
	    
        // keep track of the visited cell
	    vector<vector<int>> vis(n,vector<int>(m,0));

        // keep track of the distance of nearest 1 from current cell
	    vector<vector<int>> dist(n,vector<int>(m,0));
	    
        // for BFS traversal
	    queue<pair<pair<int,int>,int>> q;
	    
        // push all the 1's cell into queue and mark them as visited
	    for(int i=0; i<n; i++){
	        for(int j=0; j<m; j++){
	            if(grid[i][j] == 1){
	                q.push({{i,j},0});
	                vis[i][j] = 1;
	            }
	        }
	    }
	    
        // BFS Traversal
	    while(!q.empty()){
	        int row = q.front().first.first;
	        int col = q.front().first.second;
	        int steps = q.front().second;
	        q.pop();
	        
            // updating distance array with steps taken to reach nearest 1 for current cell
	        dist[row][col] = steps;
	        
            // coordinates for 4 directions
	        int delRow[] = {0,-1,0,+1};
	        int delCol[] = {-1,0,+1,0};
	        
            // move in all 4 directions
	        for(int i=0; i<4; i++){
	            int nrow = row + delRow[i];
	            int ncol = col + delCol[i];
	            
                // check for cell validity and if it is not visited
	            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol]){
	                q.push({{nrow,ncol},steps+1}); // if the cell is not visited, then increase steps by 1 and push it into queue
	                vis[nrow][ncol] = 1; // mark the cell as visited
	            }
	        }
	    }
	    
	    return dist;
	}
};
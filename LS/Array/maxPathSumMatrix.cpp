// Link: https://practice.geeksforgeeks.org/problems/path-in-matrix3805/1

// Approach 1: [TC: O(N*N), SC: O(N*N)]

class Solution{
public:
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        // Creating a new matrix to store path sum at each step in matrix
        int dp[N][N];
        
        // Storing the values in first row to start the path
        for(int i=0; i<N; i++) dp[0][i] = Matrix[0][i];
        
        /*
        Starting from row 1 to calculate values using previous row as we move down
            [ For row 1, previous row -> row 0
              For row 2 previous row -> row 1
              For row 3 previous row -> row 2 ]
        */
        for(int r=1; r<N; r++){
            for(int c=0; c<N; c++){
                
                // Storing the value of upper left cell after checking validity
                int upLeft=0;
                if(c-1>=0) upLeft=dp[r-1][c-1];
                
                // Storing the value of upper
                int up=dp[r-1][c];
                
                // Storing the value of upper right cell after checking validity
                int upRight=0;
                if(c+1<N) upRight=dp[r-1][c+1];
                
                /*
                Adding the max value among cells in previous row to the current row in 'Matrix',
                and storing the resultant value in the current row of 'dp' matrix
                */
                dp[r][c] = Matrix[r][c] + max({upLeft,up,upRight});
            }
        }
        
        int ans=0;
        
        // Now all the resultant max path sum are stored in the last row of the 'dp' matrix
        for(int c=0; c<N; c++){
            // Iterating through the last row of 'dp' matrix to find the maximum path sum
            ans=max(ans,dp[N-1][c]);
        }
        
        return ans;
    }
};

// Approach 2: [TC: O(N*N), SC: O(N)]

class Solution{
public:
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        // Creating a new matrix with just one row to store path sum at each step in matrix
        int dp[N];
        
        // Storing the values in 'dp' matrix to start the path
        for(int i=0; i<N; i++) dp[i] = Matrix[0][i];
        
        /*
        Starting from row 1 to calculate values using previous row as we move down
            [ For row 1, previous row -> row 0
              For row 2 previous row -> row 1
              For row 3 previous row -> row 2 ]
        */
        for(int r=1; r<N; r++){
            int upLeft=0; // Staring with upLeft cell=0 for each new row
            for(int c=0; c<N; c++){
                // Storing the value of upper
                int up=dp[c];
                
                // Storing the value of upper right cell after checking validity
                int upRight=0;
                if(c+1<N) upRight=dp[c+1];
                
                /*
                Adding the max value among cells in previous row to the current row in 'Matrix',
                and storing the resultant value in the current row of 'dp' matrix
                */
                dp[c] = Matrix[r][c] + max({upLeft,up,upRight});
                
                upLeft = up; // as we move horizontally(0->N-1 columns) in the row, 'up' will become 'upLeft'
            }
        }
        
        int ans=0;
        
        // Now all the resultant max path sum are stored in the 'dp' matrix
        for(int c=0; c<N; c++){
            // Iterating through the 'dp' matrix to find the maximum path sum
            ans=max(ans,dp[c]);
        }
        
        return ans;
    }
};
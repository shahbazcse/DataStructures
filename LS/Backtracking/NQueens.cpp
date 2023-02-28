// Link: https://practice.geeksforgeeks.org/problems/n-queen-problem0315/1

// Approach 1: Recursion + Backtracking [TC: O(!N * N) / Aux. SC: O(N^2)]

class Solution{
public:
    bool isSafe(int n, vector<string> &board, int row, int col){
        int duprow = row;
        int dupcol = col;
        
        while(row>=0 && col>=0){
            if(board[row][col] == 'Q') return false;
            row--;
            col--;
        }
        
        col = dupcol;
        row = duprow;
        while(col>=0){
            if(board[row][col] == 'Q') return false;
            col--;
        }
        
        col = dupcol;
        row = duprow;
        while(row<n && col>=0){
            if(board[row][col] == 'Q') return false;
            row++;
            col--;
        }
        
        return true;
    }
    void solve(int n, vector<vector<int>> &ans, vector<string> &board, vector<int> &ds, int col){
        if(col==n){
            ans.push_back(ds);
            return;
        }
        
        for(int row=0; row<n; row++){
            if(isSafe(n,board,row,col)){
                board[row][col] = 'Q';
                ds.push_back(row+1); // 1-based indexing for col for 0-based row indexing
                
                solve(n,ans,board,ds,col+1);
                
                // backtracking
                ds.pop_back();
                board[row][col] = '.';
            }
        }
    }
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> ans;
        vector<int> ds;
        vector<string> board(n,string(n,'.'));
        solve(n,ans,board,ds,0);
        return ans;
    }
};

// Approach 2: Recursion + Hashing [TC: O(!N) / Aux. SC: O(N^2)]

class Solution{
public:
    void solve(int n, vector<vector<int>> &ans, vector<int> &ds, 
    vector<int> &leftRow, vector<int> &upperDiagonal, vector<int> &lowerDiagonal, int col){
        if(col==n){
            ans.push_back(ds);
            return;
        }
        
        for(int row=0; row<n; row++){
            // Check left row, upper diagonal, and lower diagonal for other queens, if not present, then proceed
            if(leftRow[row] == 0 && lowerDiagonal[row+col] == 0 && upperDiagonal[n-1 + col - row] == 0){
                leftRow[row] = 1;
                lowerDiagonal[row+col] = 1;
                upperDiagonal[n-1 + col - row] = 1;
                
                ds.push_back(row+1); // 1-based indexing for col for 0-based row indexing
                
                solve(n,ans,ds,leftRow,upperDiagonal,lowerDiagonal,col+1);
                
                // backtracking
                leftRow[row] = 0;
                lowerDiagonal[row+col] = 0;
                upperDiagonal[n-1 + col - row] = 0;
                
                ds.pop_back();
            }
        }
    }
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> ans;
        vector<int> ds;

        // Hash Array
        vector<int> leftRow(n,0), upperDiagonal(2*n-1,0), lowerDiagonal(2*n-1,0);
        
        solve(n,ans,ds,leftRow,upperDiagonal,lowerDiagonal,0);
        
        return ans;
    }
};
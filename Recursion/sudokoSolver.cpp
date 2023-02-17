// Link: https://practice.geeksforgeeks.org/problems/solve-the-sudoku-1587115621/1

// Approach: [TC: O(9^(N*N)) / SC: O(N*N)]

class Solution 
{
    public:
    bool isValid(int grid[N][N], int row, int col, int k){
        for(int i=0; i<9; i++){
            // check if k already exists in row
            if(grid[row][i] == k){
                return false;
            }
            
            // check if k already exists in column
            if(grid[i][col] == k){
                return false;
            }
            
            // check if k already exists in sub-grid
            if(grid[3*(row/3) + i/3][3*(col/3) + i%3] == k){
                return false;
            }
        }
        // return true, if k is not already present, mean we have a valid space for k
        return true;
    }
    bool solve(int grid[N][N]){
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                // check for empty space
                if(grid[i][j] == 0){
                    for(int k=1; k<=9; k++){
                        if(isValid(grid,i,j,k)){
                            grid[i][j] = k;
                            // return true, if k is valid (for subsequent recursive calls) for the given space
                            if(solve(grid)) return true;
                            else grid[i][j] = 0;
                        }
                    }
                    // return false if k is not valid for the given space and for the subsequent recursive calls
                    return false;
                }
            }
        }
        // return true if k is valid, and filled in the given space in every recursive call successfully
        return true;
    }
    //Function to find a solved Sudoku. 
    bool SolveSudoku(int grid[N][N])  
    { 
        solve(grid);
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                cout<<grid[i][j]<<" ";
            }
        }
    }
};
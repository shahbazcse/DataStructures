// Link: https://leetcode.com/problems/search-a-2d-matrix-ii/

// Approach 1: Using Binary Search [TC: O()]

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size();
        int col=matrix[0].size();

        int rowIdx=0;
        int colIdx=col-1;

        while(rowIdx<row && colIdx>=0){
            int element = matrix[rowIdx][colIdx];

            if(element == target) return true;

            if(element>target) colIdx--;
            else rowIdx++;
        }
        return false;
    }
};
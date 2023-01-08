// Link: https://leetcode.com/problems/search-a-2d-matrix/

// Approach 1: [TC: O(m*n)]

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix[0].size();
        int n=matrix.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j]==target) return true;
            }
        }
        return false;
    }
};

// Approach 2: Using Binary Search [TC: O(log(m*n)]

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size();
        int col=matrix[0].size();

        int s=0;
        int e=(row*col)-1;
        int mid=s+(e-s)/2;
        
        while(s<=e){
            int element=matrix[mid/col][mid%col];
            if(element==target) return true;
            
            if(element<target) s=mid+1;
            else e=mid-1;
            
            mid=s+(e-s)/2;
        }
        return false;
    }
};
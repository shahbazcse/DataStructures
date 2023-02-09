// Link: https://leetcode.com/problems/rotate-image/

// Approach: [TC: O(N^2) / SC: O(1)]

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        reverse(matrix.begin(),matrix.end());
        for(int i=0; i<matrix.size(); i++){
            for(int j=i+1; j<matrix[0].size(); j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
    }
};
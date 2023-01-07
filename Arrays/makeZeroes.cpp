// Link: https://practice.geeksforgeeks.org/problems/make-zeroes4042/1

class Solution {
public:
    void MakeZeros(vector<vector<int> >& matrix) {
        
        vector<vector<int>> ans=matrix;
        
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                if(matrix[i][j]==0){
                    if(i-1>=0){
                        ans[i][j]+=matrix[i-1][j];
                        ans[i-1][j]=0;
                    }
                    if(j-1>=0){
                        ans[i][j]+=matrix[i][j-1];
                        ans[i][j-1]=0;    
                    }
                    if(i+1<matrix.size()){
                        ans[i][j]+=matrix[i+1][j];
                        ans[i+1][j]=0;
                    }
                    if(j+1<matrix[0].size()){
                        ans[i][j]+=matrix[i][j+1];
                        ans[i][j+1]=0;
                    }
                }
            }
        }
        
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                matrix[i][j]=ans[i][j];
            }
        }
        
    }
};
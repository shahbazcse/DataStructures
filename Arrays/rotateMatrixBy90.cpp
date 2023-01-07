// Link: https://practice.geeksforgeeks.org/problems/rotate-by-90-degree-1587115621/1

class Solution
{   
    public:
    //Function to rotate matrix anticlockwise by 90 degrees.
    void rotateby90(vector<vector<int> >& matrix, int n) 
    { 
        vector<int> ds;
        
        int top=0;
        int bottom=n-1;
        int left=0;
        int right=n-1;
        
        while(top<=bottom && left<=right){
            for(int i=top; i<=bottom; i++){
                ds.push_back(matrix[i][right]);
            }
            right--;
            
            if(left<=right){
                for(int i=top; i<=bottom; i++){
                    ds.push_back(matrix[i][right]);
                }
                right--;
            }
            
            if(left<=right){
                for(int i=top; i<=bottom; i++){
                    ds.push_back(matrix[i][right]);
                }
                right--;
            }
            
            if(left>right) break;
        }
        int k=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                matrix[i][j]=ds[k];
                k++;
            }
        }
    } 
};
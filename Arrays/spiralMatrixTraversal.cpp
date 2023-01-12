// Link: https://practice.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1

// Approach 1: Using TOP/BOTTOM/LEFT/RIGHT Approach [TC: O(R*C)]

class Solution
{   
    public: 
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        vector<int> list;
        
        int top=0;
        int bottom=r-1;
        int left=0;
        int right=c-1;
        
        while(top<=bottom && left<=right){
            for(int i=left; i<=right; i++){
                list.push_back(matrix[top][i]);
            }
            top++;
            
            for(int i=top; i<=bottom; i++){
                list.push_back(matrix[i][right]);
            }
            right--;
            
            if(top<=bottom){
                for(int i=right; i>=left; i--){
                    list.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            
            if(top>bottom) break;
            
            if(left<=right){
                for(int i=bottom; i>=top; i--){
                    list.push_back(matrix[i][left]);
                }
                left++;
            }
            
            if(left>right) break;
        }
        
        return list;
    }
};

// Link: Approach 2: Using Recursion with TOP/BOTTOM/LEFT/RIGHT Approach [TC: O(R*C)]

class Solution
{   
    public: 
    void helper(vector<vector<int> > matrix, vector<int> &list, int i, int j, int r, int c){
        int top=i;
        int bottom=r;
        int left=j;
        int right=c;
        
        // Base Case
        if(top>=bottom || left>=right){
            return;
        }
        
        // Logic
            for(int i=left; i<right; i++){
                list.push_back(matrix[top][i]);
            }
            
            for(int i=top+1; i<bottom; i++){
                list.push_back(matrix[i][right-1]);
            }
            
            if(bottom-1!=top){
                for(int i=right-2; i>=left; i--){
                    list.push_back(matrix[bottom-1][i]);
                }
            }
            
            if(right-1!=left){
                for(int i=bottom-2; i>top; i--){
                    list.push_back(matrix[i][left]);
                }
            }

        // Recursive call    
        helper(matrix,list,i+1,j+1,r-1,c-1);
    }

    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        vector<int> list;
        
        helper(matrix,list,0,0,r,c);
        
        return list;
    }
};
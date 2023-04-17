// Link: https://practice.geeksforgeeks.org/problems/flood-fill-algorithm1856/1

// Approach: DFS Traversal [TC O(R*C) / SC: O(R*C)]

class Solution {
public:
    void dfs(vector<vector<int>> &img, int r, int c, int newColor, int oldColor, int delRow[], int delCol[]){
        int row = img.size();
        int col = img[0].size();
        
        // checking validity of cell boundary and cell color
        if(r>=row || r<0 || c>=col || c<0 || img[r][c]==newColor || img[r][c]!=oldColor) return;
        
        // change the color of cell if it is neighbour cell and unvisited
        img[r][c] = newColor;
        
        // make recursive calls in all 4 directions from current cell
        for(int i=0; i<4; i++){
            dfs(img,r+delRow[i],c+delCol[i],newColor,oldColor,delRow,delCol);
        }
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        vector<vector<int>> img = image;
        int oldColor = img[sr][sc];
        
        // delta coordinates to move in all 4 direction from current cell
        int delRow[] = {-1,0,+1,0};
        int delCol[] = {0,+1,0,-1};
        
        dfs(img,sr,sc,newColor,oldColor,delRow,delCol);
        
        return img;
    }
};
// Link: https://www.geeksforgeeks.org/find-paths-from-corner-cell-to-middle-cell-in-maze/

// Approach: Backtracking [TC: O(4^(N^2)) / SC: O(N^2)]

#include <bits/stdc++.h>
using namespace std;

#define N 9 // size of maze

vector<pair<int,int>> path; // vector to store the current path

// function to print the current path
void print() {
    for(int i=0; i<path.size(); i++) {
        if(i==path.size()-1) cout<<"MID ("<<path[i].first<<","<<path[i].second<<")"; // middle cell
        else cout<<"("<<path[i].first<<","<<path[i].second<<")"<<" -> "; // path
    }
}

// recursive function to solve the maze
void solve(int i, int j, int mat[N][N]) {
   // if current cell is out of bounds or visited, return
   if(i<0 || j<0 || i>=N || j>=N || mat[i][j]==-1) {
       return;
   }
   
   // if current cell is the middle cell, print the path
   if(i==N/2 && j==N/2) {
       path.push_back({i,j}); // add middle cell to path
       print(); // print the path
       return;
   }
   
   int val = mat[i][j]; // save the value of current cell
   
   mat[i][j] = -1; // mark current cell as visited
   
   path.push_back({i,j}); // add current cell to path
   
   // recursively solve for the four adjacent cells

   solve(i+val, j, mat); // explores the path by moving down by val steps
   solve(i, j+val, mat); // explores the path by moving right by val steps
   solve(i-val, j, mat); // explores the path by moving up by val steps
   solve(i, j-val, mat); // explores the path by moving left by val steps
   
   mat[i][j] = val; // backtrack: mark current cell as unvisited
   
   path.pop_back(); // backtrack: remove current cell from path
}

int main() {
    // initialize maze
    int maze[N][N] = {
        { 3, 5, 4, 4, 7, 3, 4, 6, 3 },
        { 6, 7, 5, 6, 6, 2, 6, 6, 2 },
        { 3, 3, 4, 3, 2, 5, 4, 7, 2 },
        { 6, 5, 5, 1, 2, 3, 6, 5, 6 },
        { 3, 3, 4, 3, 0, 1, 4, 3, 4 },
        { 3, 5, 4, 3, 2, 2, 3, 3, 5 },
        { 3, 5, 4, 3, 2, 6, 4, 4, 3 },
        { 3, 5, 1, 3, 7, 5, 3, 6, 4 },
        { 6, 2, 4, 3, 4, 5, 4, 5, 1 }
    };
    
    // solve the maze starting from each of the four corners
    
    solve(0, 0, maze); // top-left corner
    solve(0, N-1, maze); // top-right corner
    solve(N-1, 0, maze); // bottom-left corner
    solve(N-1, N-1, maze); // bottom-right corner
    
    return 0;
}
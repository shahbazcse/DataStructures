// Link: https://leetcode.com/problems/reaching-points/

// Approach: Recursion [TC: O(log(max(tx,ty))) / SC: O(log(max(tx,ty)))]

class Solution {
public:
    // This recursive function checks if it's possible to reach the point (tx, ty) from (sx, sy) using allowed moves
    bool recurse(int sx, int sy, int tx, int ty) {
        if (tx < sx) { // if we've gone too far in the x direction, we can't reach (tx, ty)
            return false;
        }
        else if (tx == sx) { // if we can only move in the y direction, check if we can reach (tx, ty) by only moving in y direction
            return ((ty - sy) % sx) == 0;
        }
        else { // otherwise, we can still move in both x and y directions, so recursively call the function with new arguments
            return recurse(sy, sx, ty % tx, tx); // swap x and y values because next move will be in the y direction
        }
    }
    
    // This function checks if it's possible to reach (tx, ty) from (sx, sy)
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        if(tx<sx || ty<sy) return false; // if (tx, ty) is not reachable from (sx, sy), return false
        if (tx < ty) { // if x distance is less than y distance, make sure to move in x direction first
            return recurse(sx, sy, tx, ty);
        }
        else { // otherwise, move in y direction first
            return recurse(sy, sx, ty, tx);
        }
    }
};

// Link: https://www.codingninjas.com/codestudio/problems/reach-the-destination_992853

// Approach: Recursion [TC: O(N) / SC: O(N)]

bool solve(int sx, int sy, int dx, int dy){
    if(sx==dx && sy==dy) return true;
    if(dx<1 || dy<1) return false;

    return (solve(sx,sy,dx-dy,dy) || solve(sx,sy,dx,dy-dx));
}

bool reachDestination(int sx, int sy, int dx, int dy) {
    if(solve(sx,sy,dx,dy)) return true;
    else return false;
}
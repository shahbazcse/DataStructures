// Link: https://practice.geeksforgeeks.org/problems/introduction-to-trees/1

// Approach: Iterative [TC: O(i) / SC: O(1)]

class Solution {
  public:
    int countNodes(int i) {
        if(i==1) return 1;
        
        int cnt=1;
        
        for(int k=1; k<i; k++){
            cnt *= 2;
        }
        
        return cnt;
    }
};
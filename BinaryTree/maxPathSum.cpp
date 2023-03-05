// Link: https://leetcode.com/problems/binary-tree-maximum-path-sum/

// Approach: Recursion [TC: O(N) / SC: O(N)]

class Solution {
public:
    int solve(TreeNode* root, int &maxi){
        // if root is null, return 0
        if(root==NULL) return 0;

        // recursively compute the maximum sum of a path from the left and right subtrees
        int lSum = max(0,solve(root->left,maxi));
        int rSum = max(0,solve(root->right,maxi));

        // update the maximum sum if the path through the root has a higher sum than the current maximum
        maxi = max(maxi,lSum + rSum + (root->val));

        // return the maximum sum of a path that includes either the left or right subtree plus the root value
        return (root->val) + max(lSum,rSum);
    }
    
    int maxPathSum(TreeNode* root) {
        // initialize the maximum sum to the smallest possible integer value
        int maxi = INT_MIN;
        
        // compute the maximum sum by calling the solve function on the root
        solve(root,maxi);
        
        // return the maximum sum
        return maxi;
    }
};
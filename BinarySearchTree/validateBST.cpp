// Link: https://leetcode.com/problems/validate-binary-search-tree/

// Approach: [TC: O(N) / SC: O(N)]

class Solution {
public:
    bool helper(TreeNode* root, long min, long max){
        if(root==NULL) return true;
        
        // check whether the current node's value lies with the min-max range or not
        if(root->val <= min || root->val >= max) return false;

        // update the min-max ranges for left and right child nodes accordingly and make recursive calls them
        return helper(root->left,min,root->val) && helper(root->right,root->val,max);
    }
    bool isValidBST(TreeNode* root) {
        return helper(root,LONG_MIN,LONG_MAX);
    }
};
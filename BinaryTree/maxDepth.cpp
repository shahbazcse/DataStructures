// Link: https://leetcode.com/problems/maximum-depth-of-binary-tree/

// Approach: Recursion [TC: O(N) / SC: O(N)]

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        // if reached the leaf node, return 0 as there is no depth(no nodes) further
        if(root==NULL) return 0;

        // make recursive calls to count depth for left and right child nodes and store the returned depth count
        int l = maxDepth(root->left);
        int r = maxDepth(root->right);

        // add 1 (for current node) and the max of depths returned from both left and right child nodes
        return 1 + max(l,r);
    }
};
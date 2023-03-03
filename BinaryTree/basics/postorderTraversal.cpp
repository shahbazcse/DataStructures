// Link: https://leetcode.com/problems/binary-tree-postorder-traversal

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

// Postorder Traversal: (LEFT RIGHT ROOT) 

class Solution {
public:
    void solve(TreeNode* root, vector<int> &ans){
        if(root==NULL) return;

        // left
        solve(root->left,ans);

        // right
        solve(root->right,ans);

        // root
        ans.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        solve(root,ans);
        return ans;
    }
};
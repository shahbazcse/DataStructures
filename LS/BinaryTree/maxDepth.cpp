// Link: https://leetcode.com/problems/maximum-depth-of-binary-tree/

// Approach 1: Recursion [TC: O(N) / SC: O(N)]

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

// Approach 2: Level Order Traversal [TC: O(N) / SC: O(N)]

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0; // if there are no nodes, then height is zero

        int height=0;

        // Level Order Traversal
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            for(int i=0; i<size; i++){
                TreeNode* node = q.front();
                q.pop();

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            height++; // at each level increase height by 1
        }
        return height;
    }
};
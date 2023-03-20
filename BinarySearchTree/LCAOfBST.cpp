// Link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

// Approach 1: Recursion [TC: O(Height) / SC: O(Height)]

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL) return NULL;

        // Both are on left
        if(root->val > p->val && root->val > q->val){
            return lowestCommonAncestor(root->left,p,q);
        } // Both are on right
        else if(root->val < p->val && root->val < q->val){
            return lowestCommonAncestor(root->right,p,q);
        }

        // if both are not on the either side of current node, then current node is the point of intersection or LCA of p and q, so return current node
        return root;
    }
};
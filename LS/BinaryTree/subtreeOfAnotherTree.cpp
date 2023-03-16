// Link: https://leetcode.com/problems/subtree-of-another-tree

// Approach: Recursion + Identical Trees [TC: O(N) / SC: O(N)]

class Solution {
public:
    bool isIdentical(TreeNode* p, TreeNode* q){
        // if nodes of both p and q are NULL, then they are identical, hence return true
        if(p==NULL || q==NULL) return p==q;

        /*
            check if values of current nodes in both trees are equal, then make recursive calls 
            for further left and right nodes and check all nodes, return true if both trees are identical
        */
        return (p->val==q->val) && isIdentical(p->left,q->left) && isIdentical(p->right,q->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // if root becomes NULL at any point while subRoot is not NULL, then both are not identical, hence return false
        if(root==NULL) return false;

        // check for current root and subRoot, if they are identical, return true, else make further recursive calls to check for left and right subtrees of root, if either of them are identical, return true
        return isIdentical(root,subRoot) || isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }
};
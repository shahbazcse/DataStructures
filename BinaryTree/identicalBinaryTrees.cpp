// Link: https://leetcode.com/problems/same-tree

// Approach: Recursion [TC: O(N) / SC: O(N)]

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // if either of them is NULL, the other must be NULL too if both trees are identical, hence return true
        // if either of them is not NULL, then they are not identical, return false
        if(p==NULL || q==NULL){
            return p==q;
        }

        // check if values of both current nodes are equal and make recursive calls to check their child nodes, if they all are identical, return true
        return (p->val == q->val) && isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }
};
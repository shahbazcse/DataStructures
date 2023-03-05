// Link: https://leetcode.com/problems/same-tree

// Approach: Recursion [TC: O(N) / SC: O(N)]

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // if either of them is NULL, the other must be NULL too if both trees are identical
        if(p==NULL || q==NULL){
            if(p==q) return true; // return true, if both nodes are NULL
            else return false; // return false, if either of them is not NULL
        }

        // check if values of both current nodes are equal and make recursive calls to check their child nodes, if they all are identical, return true
        if(p->val == q->val && isSameTree(p->left,q->left) && isSameTree(p->right,q->right)) return true;
        else return false; // return false, if the current nodes are unequal or their child nodes are not identical
    }
};
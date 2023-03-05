// Link: https://leetcode.com/problems/balanced-binary-tree/

// Appraoch: Recursion [TC: O(N) / SC: O(N)]

class Solution {
public:
    int dfsHeight(TreeNode* root){
        // if reached the leaf node, return 0 as there is no depth(no nodes) further
        if(root==NULL) return 0;

        // make recursive calls to count depth for left and right child nodes and store the returned depth count
        int l = dfsHeight(root->left);
        int r = dfsHeight(root->right);

        // if either of left or right child node returns -1, it means tree is unbalanced
        if(l==-1 ||r==-1) return -1;

        // if the difference between height of left and right node is greater than 1, it means tree is unbalanced
        if(abs(l-r)>1) return -1; // return -1 for unbalanced tree

        // if difference between height of left and right node is less than or equal to 1, it means tree is balanced
        
        // add 1 (for current node) and the max of depths returned from both left and right child nodes
        return 1 + max(l,r); // return the actual height of tree
    }
    bool isBalanced(TreeNode* root) {
        if(dfsHeight(root)!=-1) return true;
        else return false;
    }
};
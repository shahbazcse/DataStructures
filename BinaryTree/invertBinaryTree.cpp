// Link: https://leetcode.com/problems/invert-binary-tree

// Approach: Recursion + Swap [TC: O(N) / Aux. SC: O(N)]

class Solution {
public:
    void invertBT(TreeNode* &root){
        if(root==NULL) return;

        invertBT(root->left);
        invertBT(root->right);

        // if the child nodes are not a leaf node, swap both the child nodes with data and address
        if(root->left || root->right) swap(root->left,root->right);
    }

    TreeNode* invertTree(TreeNode* root) {
        invertBT(root);
        return root;
    }
};
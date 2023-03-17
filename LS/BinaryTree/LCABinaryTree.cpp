// Link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree

// Approach: Recursion + Postorder Traversal [TC: O(N) / Aux. SC: O(N)]

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Base case: If the root is null or one of the nodes is the root, return the root.
        if(root==NULL || root==p || root==q) return root;

        // Recursively call the function on the left and right subtrees of the current node.
        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);

        // If the left subtree does not contain either of the nodes, the lowest common ancestor is in the right subtree.
        if(left==NULL) return right;
        // If the right subtree does not contain either of the nodes, the lowest common ancestor is in the left subtree.
        else if(right==NULL) return left;
        // If both subtrees contain one of the nodes, the current node is the lowest common ancestor.
        else return root;
    }
};
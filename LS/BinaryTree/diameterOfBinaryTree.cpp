// Link: https://leetcode.com/problems/diameter-of-binary-tree/

// Approach 1: Recursion + maxDepth [TC: O(N^2) / SC: O(N)]

class Solution {
public:
    int maxi=0;
    int maxDepth(TreeNode* root){
        if(root==NULL) return 0;

        int l = maxDepth(root->left);
        int r = maxDepth(root->right);

        return 1 + max(l,r);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;

        int l = maxDepth(root->left);
        int r = maxDepth(root->right);

        maxi = max(maxi,l+r);

        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);

        return maxi;
    }
};

// Approach 2: Optimized Recursion [TC: O(N) / SC: O(N)]

class Solution {
public:
    // Helper function to compute the height of the binary tree rooted at "root"
    int height(TreeNode* root, int &diameter){
        // If the current subtree is empty, return 0
        if(root==NULL) return 0;

        // Recursively compute the height of the left and right subtrees
        int l = height(root->left,diameter);
        int r = height(root->right,diameter);

        // Compute the diameter of the binary tree as the maximum of the sum of the heights of the left and right subtrees
        diameter = max(diameter,l+r);

        // Return the height of the current subtree as 1 plus the maximum of the heights of the left and right subtrees
        return 1 + max(l,r);
    }

    // Function to compute the diameter of the binary tree
    int diameterOfBinaryTree(TreeNode* root) {
        // Initialize the diameter to 0
        int diameter = 0;
        // Compute the height of the binary tree and update the diameter along the way
        height(root,diameter);
        // Return the diameter of the binary tree
        return diameter;
    }
};
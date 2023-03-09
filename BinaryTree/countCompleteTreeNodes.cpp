// Link: https://leetcode.com/problems/count-complete-tree-nodes

// Approach: Recursion + Height Of Tree [TC: O((LogN)^2) / SC: O(LogN)]

class Solution {
public:
    // Function to calculate the height of the left subtree
    int leftHeight(TreeNode* node){
        int cnt=0;

        while(node){
            cnt++;              // Increment the counter for each level
            node=node->left;    // Traverse down the left child
        }
        return cnt;
    }

    // Function to calculate the height of the right subtree
    int rightHeight(TreeNode* node){
        int cnt=0;

        while(node){
            cnt++;              // Increment the counter for each level
            node=node->right;   // Traverse down the right child
        }
        return cnt;
    }

    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;    // Base case: empty tree has zero nodes

        int lh = leftHeight(root);  // Calculate the height of the left subtree
        int rh = rightHeight(root); // Calculate the height of the right subtree

        // If heights are equal, it is a full binary tree, return the number of nodes using the formula 2^h - 1
        if(lh==rh) return pow(2,lh)-1;

        // If heights are not equal, recursively count the number of nodes in the left and right subtrees and add 1 for the root node
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};
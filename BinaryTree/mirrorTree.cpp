// Link: https://practice.geeksforgeeks.org/problems/mirror-tree/1

// Approach: Recursion + Swap [TC: O(N) / SC: O(N)]

class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* node) {
        if(node==NULL) return;
        
        mirror(node->left);
        mirror(node->right);

        // if the child nodes are not a leaf node, swap both the child nodes with data and address
        if(node->left || node->right) swap(node->left,node->right);
    }
};
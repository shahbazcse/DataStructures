// Link: https://leetcode.com/problems/binary-tree-inorder-traversal/

// Approach: Morris Inorder Traversal [TC: O(N) / SC: O(1)]

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        // Create an empty vector to store the inorder traversal
        vector<int> inorder;
        
        // Start from the root of the tree
        TreeNode* curr = root;

        while(curr){
            // If the current node has no left child, then it is a leaf node, visit it and store it and move to its right child (if any).
            if(curr->left==NULL){
                inorder.push_back(curr->val);
                curr=curr->right;
            }else{
                // If the current node has a left child, then we need to find its 
                // in-order predecessor (i.e., the largest node in its left subtree).
                // To do this, we start from the left child and follow its right child
                // pointers until we reach a node that either has no right child or 
                // whose right child is the current node (Threading).
                TreeNode* prev = curr->left;
                while(prev->right && prev->right!=curr){
                    prev = prev->right;
                }

                if(prev->right==NULL){
                    // If we reach a node with no right child, we link it to the current node
                    // (by setting its right child to point to the current node, aka Threading) and move to 
                    // the current node's left child.
                    prev->right = curr;
                    curr = curr->left;
                }else{
                    // If we reach a node whose right child is the current node (Threading is already done), then we 
                    // have already visited its left subtree, so we unlink it (by setting 
                    // its right child to NULL), visit and store the current node, and move to its 
                    // right child (if any).
                    prev->right=NULL;
                    inorder.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        
        // Return the inorder traversal
        return inorder;
    }
};

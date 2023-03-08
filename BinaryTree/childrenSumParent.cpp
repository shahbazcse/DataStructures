// Link: https://practice.geeksforgeeks.org/problems/children-sum-parent/1

// Approach: Recursion [TC: O(N) / Aux. Sc: O(N)]

class Solution{
    public:
    //Function to check whether all nodes of a tree have the value 
    //equal to the sum of their child nodes.
    int isSumProperty(Node *root)
    {
        // if the root is NULL or root is leaf node, return true, as previous nodes must have had valid childrenSum property 
        if(root==NULL || root->left==NULL && root->right==NULL) return true;
        
        bool childrenSum = false; // flag children sum property to false 
        int left=0; // store left child node value
        int right=0; // store right child node value
        
        // If current node is not a leaf node and store data the child nodes value
        if(root->left) left = root->left->data;
        if(root->right) right = root->right->data;

        // check current node value is equal to child nodes sum, if yes, then flag childrenSum property to true
        if(root->data == left + right) childrenSum=true;
        
        // check for valid childrenSum property across all further nodes in the binary tree
        return childrenSum && isSumProperty(root->left) && isSumProperty(root->right);
    }
};
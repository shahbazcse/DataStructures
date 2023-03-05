// Link: https://practice.geeksforgeeks.org/problems/root-to-leaf-path-sum/1

// Approach: Recursion [TC: O() / SC: O()]

class Solution
{
    public:
    bool hasPathSum(Node *root, int S) {
        if(root==NULL || S<0) return false;
        if(S-root->data==0 && root->left==NULL && root->right==NULL) return true;
        
        return hasPathSum(root->left,S-root->data) || hasPathSum(root->right,S-root->data);
    }
};
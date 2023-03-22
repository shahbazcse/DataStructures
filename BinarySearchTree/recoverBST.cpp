// Link: https://leetcode.com/problems/recover-binary-search-tree

// Approach: Recursion + Inorder Traversal + Swap [TC: O(N) / SC: O(N)]

class Solution {
private:
    TreeNode* first;
    TreeNode* middle;
    TreeNode* last;
    TreeNode* prev;

public:
    void inorder(TreeNode* root){
        if(root==NULL) return;

        inorder(root->left);

        // check for violations and store nodes in first, middle and last
        if(prev && (root->val < prev->val)){
            // if it is first voilation, store prev node in first and current node in middle
            if(first==NULL){
                first = prev;
                middle = root;
            }
            // if it is second voilation, store current node in last
            else last = root;
        }

        // track previous node
        prev = root;

        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        first = middle = last = prev = NULL;

        // do inorder traversal
        inorder(root);

        // Non-adjacent nodes case
        if(first && last) swap(first->val,last->val);
        // Adjacent nodes case
        else if(first && middle) swap(first->val,middle->val);    
    }
};
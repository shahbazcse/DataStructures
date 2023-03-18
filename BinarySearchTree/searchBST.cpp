// Link: https://leetcode.com/problems/search-in-a-binary-search-tree

// Approach 1: Recursion [TC: O(Height) / Sc: O(Height)]

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root==NULL) return NULL;

        if(root->val == val) return root;

        return root->val > val ? searchBST(root->left,val) : searchBST(root->right,val);
    }
};

// Approach 2: Iterative [TC: O(Height) / SC: O(1)]

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while(root!=NULL && root->val!=val){
            root = root->val > val ? root->left : root->right;
        }
        return root;
    }
};
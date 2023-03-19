// Link: https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/

// Approach: Recursion [TC: O(N) / SC: O(N)]

class Solution {
public:
    void helper(TreeNode* root, int &k, int &ans){
        if(root==NULL) return;

        helper(root->left,k,ans);
        
        k--;
        if(k==0){
            ans = root->val;
            return;
        }

        helper(root->right,k,ans);
    }

    int kthSmallest(TreeNode* root, int k) {
        int ans=0;
        helper(root,k,ans);
        return ans;
    }
};
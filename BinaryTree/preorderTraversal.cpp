// Link: https://leetcode.com/problems/binary-tree-preorder-traversal

// Approach 1: Recursion [TC: O(N) / SC: O(N)]

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

 // Preorder Traversal: (ROOT LEFT RIGHT)

class Solution {
public:
    void solve(TreeNode* root, vector<int> &ans){
        if(root==NULL) return;

        // root
        ans.push_back(root->val);

        // left
        solve(root->left,ans);
        
        // right
        solve(root->right,ans);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        solve(root,ans);
        return ans;
    }
};

// Approach 2: Iterative + Stack [TC: O(N) / SC: O(N)]

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root==NULL) return ans;

        stack<TreeNode*> st;
        st.push(root);

        while(!st.empty()){
            TreeNode* top = st.top();
            st.pop();

            ans.push_back(top->val);

            if(top->right!=NULL) st.push(top->right);
            if(top->left!=NULL) st.push(top->left);

        }
        return ans;
    }
};
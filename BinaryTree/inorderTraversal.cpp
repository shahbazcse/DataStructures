// Link: https://leetcode.com/problems/binary-tree-inorder-traversal

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

// Inorder Traversal: (LEFT ROOT RIGHT)

class Solution {
public:
    void solve(TreeNode* root, vector<int> &ans){
        if(root==NULL) return;

        // left
        solve(root->left,ans);
        
        // root
        ans.push_back(root->val);

        // right
        solve(root->right,ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root==NULL) return ans;

        TreeNode* top = root;
        
        stack<TreeNode*> st;

        while(1){
            if(top!=NULL){
                st.push(top);
                top = top->left;
            }else{
                if(st.empty()) break;
                top = st.top();
                st.pop();
                ans.push_back(top->val);
                top = top->right;
            }
        }
        return ans;
    }
};
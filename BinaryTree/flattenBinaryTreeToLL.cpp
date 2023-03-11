// Link: https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

// Approach 1: Recursion [TC: O(N) / SC: O(N)]

class Solution {
public:
    TreeNode* prev = NULL;
    void flatten(TreeNode* root){
        if(root==NULL) return;

        flatten(root->right);
        flatten(root->left);

        root->right = prev;
        root->left = NULL;
        prev = root;
    }
};

// Approach 2: Iterative + Stack [TC: O(N) / SC: O(N)]

class Solution {
public:
    void flatten(TreeNode* root) {
        if(root==NULL) return;

        stack<TreeNode*> st;
        st.push(root);

        while(!st.empty()){
            TreeNode* node = st.top();
            st.pop();

            if(node->right) st.push(node->right);
            if(node->left) st.push(node->left);

            if(!st.empty()) node->right = st.top();
            node->left = NULL;
        }
    }
};

// Approach 3: Morris Traversal [TC: O(N) / SC: O(1)]

class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* curr = root;

        while(curr){
            if(curr->left){
                TreeNode* prev = curr->left;

                while(prev->right){
                    prev = prev->right;
                }

                prev->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
            curr = curr->right;
        }
    }
};
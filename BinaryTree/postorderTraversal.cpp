// Link: https://leetcode.com/problems/binary-tree-postorder-traversal

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

// Postorder Traversal: (LEFT RIGHT ROOT) 

class Solution {
public:
    void solve(TreeNode* root, vector<int> &ans){
        if(root==NULL) return;

        // left
        solve(root->left,ans);

        // right
        solve(root->right,ans);

        // root
        ans.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        solve(root,ans);
        return ans;
    }
};

// Approach 2: Iterative + 1 Stack [TC: O(N) / SC: O(N)]

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans; // create empty vector to store node values

        TreeNode* curr = root; // set current node to root
        stack<TreeNode*> st; // create empty stack to store nodes

        while(curr || !st.empty()){ // while there are still nodes to visit
            if(curr){ // if current node exists
                st.push(curr); // push it onto the stack
                curr=curr->left; // set current to its left child
            }else{ // if current node doesn't exist
                TreeNode* top = st.top()->right; // set top to the right child of the top node on the stack
                if(!top){ // if top node has no right child or right child has already been visited
                    top = st.top(); // set top to the top node on the stack
                    st.pop(); // pop the top node off the stack

                    ans.push_back(top->val); // add top node's value to ans vector

                    // continue to pop nodes from the stack until it finds a node whose right child has not been visited yet
                    while(!st.empty() && top == st.top()->right){ 
                        top = st.top(); // set top to the top node on the stack
                        st.pop(); // pop the top node off the stack
                        ans.push_back(top->val); // add top node's value to ans vector
                    }
                }else curr = top; // if top node has a right child that hasn't been visited yet, set it as the new current node
            }
        }
        return ans; // return ans vector containing postorder traversal
    }
};

// Approach 3: Iterative + 2 Stack [TC: O(N) / SC: O(N)]

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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root==NULL) return ans;

        stack<TreeNode*> st1, st2;
        st1.push(root);

        while(!st1.empty()){
            TreeNode* top = st1.top();
            st1.pop();

            if(top->left) st1.push(top->left);
            if(top->right) st1.push(top->right);

            st2.push(top);
        }

        while(!st2.empty()){
            ans.push_back(st2.top()->val);
            st2.pop();
        }
        return ans;
    }
};

// Approach 4: Iterative + Reverse [TC: O(NLogN) / SC: O(N)]

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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root==NULL) return ans;

        stack<TreeNode*> st;
        st.push(root);

        while(!st.empty()){
            TreeNode* top = st.top();
            st.pop();

            if(top->left) st.push(top->left);
            if(top->right) st.push(top->right);

            ans.push_back(top->val);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
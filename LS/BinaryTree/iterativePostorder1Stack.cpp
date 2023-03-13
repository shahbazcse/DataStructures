// Link: https://leetcode.com/problems/binary-tree-postorder-traversal/

// Approach 1: Iterative + 1 Stack [TC: O(N) / SC: O(N)]

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
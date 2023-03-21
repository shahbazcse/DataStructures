// Link: https://leetcode.com/problems/binary-search-tree-iterator/

// Approach: Iterative + Stack [TC: O(N) / SC: O(Height)]

class BSTIterator {
private:
    stack<TreeNode*> st; // A stack of TreeNode pointers to keep track of nodes to visit

    // Helper function to push all nodes in the left subtree of the given root onto the stack
    void pushAll(TreeNode* root){
        while(root){
            st.push(root); // Push the current node onto the stack
            root = root->left; // Move to the left child
        }
    }

public:
    // Constructor that initializes the stack by pushing all nodes in the left subtree of the root node
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    // Returns the value of the next node in the BST
    int next() {
        TreeNode* curr = st.top(); // Get the top node from the stack
        st.pop(); // Remove the top node from the stack

        if(curr->right) pushAll(curr->right); // If the top node has a right subtree, push all nodes in the left subtree of the right child onto the stack

        return curr->val; // Return the value of the top node
    }
    
    // Returns true if there are more nodes to visit in the BST, false otherwise
    bool hasNext() {
        return !st.empty(); // If the stack is not empty, there are more nodes to visit
    }
};
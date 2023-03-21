// Link: https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

// Approach: Two Pointers + Queue + BST Iterator [TC: O(N) / SC: O(Height)]

// Binary Search Tree Iterator class
class BSTIterator {
private:
    stack<TreeNode*> st; // Stack to store nodes in the order they will be iterated
    bool reverse = true; // Flag to indicate whether to iterate in reverse order or not

    // Helper function to push all nodes from the current node to the stack
    // in the order they will be iterated
    void pushAll(TreeNode* root){
        while(root){
            st.push(root);
            if(!reverse) root = root->left; // If not iterating in reverse order, go left
            else root = root->right; // If iterating in reverse order, go right
        }
    }

public:
    // Constructor for the iterator
    BSTIterator(TreeNode* root, bool isReverse){
        reverse = isReverse; // initialize reverse with input bool value for type of iterator
        pushAll(root); // Push all nodes in the correct order onto the stack
    }

    // Function to return the next element in the iteration
    int next(){
        TreeNode* curr = st.top(); // Get the top node from the stack
        st.pop(); // Remove the top node from the stack

        // If not iterating in reverse order and the current node has a right child,
        // push all nodes from the right subtree onto the stack in the correct order
        if(!reverse && curr->right) pushAll(curr->right);
        
        // If iterating in reverse order and the current node has a left child,
        // push all nodes from the left subtree onto the stack in the correct order
        if(reverse && curr->left) pushAll(curr->left);

        return curr->val; // Return the value of the current node
    }

    // Function to check if there are any more elements in the iteration
    bool hasNext(){
        return !st.empty(); // Return true if there are still nodes left in the stack
    }
};

// Solution class for finding two elements in a binary search tree that sum to a given value
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(root == NULL) return false; // If the tree is empty, return false

        // Create two iterators - one for iterating through the tree in ascending order
        // and one for iterating through the tree in descending order
        BSTIterator l(root, false);
        BSTIterator r(root, true);

        int s = l.next(); // Get the first element from the ascending iterator
        int e = r.next(); // Get the first element from the descending iterator

        while(s < e){ // Keep looping while there are still elements to check
            if(s + e == k) return true; // If the sum of the two elements is equal to k, we've found a match
            else if(s + e < k) s = l.next(); // If the sum is less than k, move to the next element from the ascending iterator
            else e = r.next(); // If the sum is greater than k, move to the next element from the descending iterator
        }
        
        return false; // If we haven't found a match by this point, return false
    }
};
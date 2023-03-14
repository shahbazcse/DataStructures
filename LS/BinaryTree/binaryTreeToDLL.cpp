// Link: https://practice.geeksforgeeks.org/problems/binary-tree-to-dll/1

// Approach: Recursion + Inorder Traversal [TC: O(N) / SC: O(N)]

class Solution
{
    public: 
    //Function to convert binary tree to doubly linked list and return it.
    void helper(Node* root, Node* &tail){
        if(root==NULL) return;
        
        // inorder traversal 
        helper(root->left,tail);
        
        // point right pointer of tail to current node
        tail->right = root;
        // point left pointer of current node to tail
        if(tail->data != -1) root->left = tail;
        // update tail
        tail = tail->right;
        
        helper(root->right,tail);
    }
    
    Node * bToDLL(Node *root)
    {
        Node* head = new Node(-1);
        Node* tail = head;
        
        helper(root,tail);
        
        return head->right;
    }
};
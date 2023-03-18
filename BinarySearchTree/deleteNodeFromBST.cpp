// Link: https://practice.geeksforgeeks.org/problems/delete-a-node-from-bst/1

// Approach: Iterative [TC: O(Height) / SC: O(1)]

// This function replaces a node to be deleted with a new subtree
Node* helper(Node* root){
    // If the left child is null, return the right child (and vice versa)
    if(root->left == NULL) return root->right;
    else if(root->right == NULL) return root->left;
    
    // If both children are present, find the rightmost node in the left subtree
    Node* rightChild = root->right;
    Node* lastRight = root->left;
    while(lastRight->right){
        lastRight = lastRight->right;
    }
    
    // Attach the right subtree to the rightmost node of the left subtree
    lastRight->right = rightChild;
    
    // Return the root of the new subtree (the left child of the deleted node)
    return root->left;
}

// This function deletes a node with value X from a binary search tree
Node *deleteNode(Node *root, int X) {
    // If the root is null, return null
    if(root==NULL) return NULL;
    
    // If the root's value is equal to X, call the helper function with the root and return the result
    if(root->data == X) return helper(root);
    
    // Otherwise, traverse the tree to find the node with value X
    Node* curr = root;
    while(root){
        if(root->data > X){ // If X is less than the current node's value, go left
            if(root->left && root->left->data == X){ // If the left child has the value X, call the helper function on the left child and replace the left child with the new subtree
                root->left = helper(root->left);
                break;
            }else root = root->left; // Otherwise, keep traversing left
        }
        else{ // If X is greater than or equal to the current node's value, go right
            if(root->right && root->right->data == X){ // If the right child has the value X, call the helper function on the right child and replace the right child with the new subtree
                root->right = helper(root->right);
                break;
            }else root = root->right; // Otherwise, keep traversing right
        }
    }
    
    // Return the root of the original tree (the function signature requires it)
    return curr;
}
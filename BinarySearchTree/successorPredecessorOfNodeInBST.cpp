// Link: https://practice.geeksforgeeks.org/problems/predecessor-and-successor/1

// Approach: Iterative [TC: O(Height) / SC: O(1)]

void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    Node* curr = root; // Initialize current node as root
    
    // Find the successor of the key by traversing the right subtree of the current node until we reach a leaf node
    while(curr){
        if(key >= curr->key){ // If the key is greater than or equal to the current node's key,
            curr = curr->right; // Traverse the right subtree
        }
        else{ // Otherwise, if the key is less than the current node's key,
            suc = curr; // Set the successor to the current node
            curr = curr->left; // Traverse the left subtree
        }
    }
    
    curr = root; // Reset the current node to the root
    
    // Find the predecessor of the key by traversing the left subtree of the current node until we reach a leaf node
    while(curr){
        if(key <= curr->key){ // If the key is less than or equal to the current node's key,
            curr = curr->left; // Traverse the left subtree
        }
        else{ // Otherwise, if the key is greater than the current node's key,
            pre = curr; // Set the predecessor to the current node
            curr = curr->right; // Traverse the right subtree
        }
    }
}
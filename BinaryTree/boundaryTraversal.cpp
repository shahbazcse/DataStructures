// Link: https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1

// Approach: [TC: O(N) / SC: O(N)]

class Solution {
public:
    // Function to check if a node is a leaf node or not
    bool isLeaf(Node* root){
        if(!(root->left) && !(root->right)) return true;
        else return false;
    }
    
    // Function to add the nodes in the left boundary of the tree to the answer vector
    void addLeftBoundary(Node* root, vector<int> &ans){
        // Start with the left child of the root
        Node* curr = root->left;
        
        while(curr){
            // Add non-leaf nodes to the answer vector
            if(!isLeaf(curr)) ans.push_back(curr->data);
            
            // Traverse left if left child exists, otherwise traverse right
            if(curr->left) curr = curr->left;
            else curr = curr->right;
        }
    }
    
    // Function to add the leaf nodes of the tree to the answer vector
    void addLeaves(Node* root, vector<int> &ans){
        // Add the node to the answer vector if it is a leaf node
        if(isLeaf(root)){
            ans.push_back(root->data);
        }
        
        // Recursively traverse the left and right subtrees to add the leaf nodes to the answer vector
        if(root->left) addLeaves(root->left,ans);
        if(root->right) addLeaves(root->right,ans);
    }

    // Function to add the nodes in the right boundary of the tree to the answer vector
    void addRightBoundary(Node* root, vector<int> &ans){
        // Start with the right child of the root
        Node* curr = root->right;
        // Use a temporary vector to store the nodes in the right boundary
        vector<int> temp;
        
        while(curr){
            // Add non-leaf nodes to the temporary vector
            if(!isLeaf(curr)) temp.push_back(curr->data);
            
            // Traverse right if right child exists, otherwise traverse left
            if(curr->right) curr = curr->right;
            else curr = curr->left;
        }
        
        // Reverse the order of the nodes in the temporary vector and add them to the answer vector
        for(int i=temp.size()-1; i>=0; i--){
            ans.push_back(temp[i]);
        }
    }
    
    // Function to find the boundary traversal of the binary tree
    vector <int> boundary(Node *root)
    {
        // Create an empty vector to store the answer
        vector<int> ans;

        // If the tree is empty, return the empty vector
        if(root==NULL) return ans;
        
        // Add the root to the answer vector if it is not a leaf node
        if(!isLeaf(root)) ans.push_back(root->data);
        
        // Add the nodes in the left boundary to the answer vector
        addLeftBoundary(root,ans);

        // Add the leaf nodes to the answer vector
        addLeaves(root,ans);
        
        // Add the nodes in the right boundary to the answer vector
        addRightBoundary(root,ans);
        
        // Return the answer vector
        return ans;
    }
};
// Link: https://practice.geeksforgeeks.org/problems/insert-a-node-in-a-bst/1

// Approach 1: Recursion [TC: O(Height) / SC: O(Height)]

Node* insert(Node* root, int Key){
    if(root==NULL){
        return (new Node(Key));
    }
    
    if(root->data < Key) root->right = insert(root->right,Key);
    else if(root->data > Key) root->left = insert(root->left,Key);
    
    return root;
}

// Approach 2: Iterative [TC: O(Height) / SC: O(1)]

Node* insert(Node* root, int Key) {
    if(root==NULL) return (new Node(Key));
    
    Node* curr = root;
    
    while(1){
        if(curr->data == Key) break;
        
        if(curr->data <= Key){
            if(curr->right) curr = curr->right;
            else {
                curr->right = new Node(Key);
                break;
            }
        }
        else{
            if(curr->left) curr = curr->left;
            else {
                curr->left = new Node(Key);
                break;
            }
        }
    }
    return root;
}
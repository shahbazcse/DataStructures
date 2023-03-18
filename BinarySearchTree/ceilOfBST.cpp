// Link: https://practice.geeksforgeeks.org/problems/implementing-ceil-in-bst/1

// Approach 1: Iterative [TC: O(Height) / SC: O(1)]

int findCeil(Node* root, int input) {
    if (root == NULL) return -1;

    int ceil = -1;
    
    while(root){
        if(root->data == input){
            ceil = root->data;
            break;
        }
        
        if(root->data < input) root = root->right;
        else{
            ceil = root->data;
            root = root->left;
        }
    }
    return ceil;
}

// Approach 2: Recursion [TC: O(Height) / SC: O(Height)]

void helper(Node* root, int input, int &ceil){
    if(root==NULL) return;
    
    if(root->data == input){
        ceil = root->data;
        return;
    }
    
    if(root->data > input){
        ceil = root->data;
        helper(root->left,input,ceil);
    }
    
    if(root->data < input) helper(root->right,input,ceil);
}

int findCeil(Node* root, int input) {
    int ceil = -1;
    
    helper(root,input,ceil);
    
    return ceil;
}
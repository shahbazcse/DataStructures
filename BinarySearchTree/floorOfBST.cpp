// Link: https://practice.geeksforgeeks.org/problems/floor-in-bst/1

// Approach: Iterative [TC: O(Height) / SC: O(1)]

int floor(Node* root, int x) {
    if (root == NULL) return -1;

    /*
        Floor returns the largest integer value which is less than or equal to x
    */
    int floor = -1;
    
    while(root){
        if(root->data == x){
            floor = root->data;
            break;
        }
        
        if(root->data < x){
            floor = root->data;
            root = root->right;
        }
        else root = root->left;
    }
    return floor;
}
// Link: https://www.codingninjas.com/codestudio/problems/childrensumproperty_790723

// Approach: Recursion [TC: O(N) / SC: Aux. O(N)]

void changeTree(BinaryTreeNode < int > * root) {
    // Base case: if the root is null, return immediately.
    if(root==NULL) return;

    // Initialize a variable to store the sum of the values of the children of the current node.
    int childSum=0;

    // Add the values of the left and right children of the current node to the childSum variable, if they exist.
    if(root->left) childSum += root->left->data;
    if(root->right) childSum += root->right->data;

    // If the sum of the children is greater than or equal to the current node's value, set the current node's value to the sum.
    if(childSum >= root->data) root->data = childSum;
    // Otherwise, if the sum of the children is smaller than to the current node's value, set the value of the left or right child to the current node's value, whichever exists.
    else{
        if(root->left) root->left->data = root->data;
        else if(root->right) root->right->data = root->data;
    }

    // Recursively call the function on the left and right subtrees of the current node.
    changeTree(root->left);
    changeTree(root->right);

    // Initialize a variable to store the sum of the values of the children of the parent of the current node.
    int parentSum=0;

    // Add the values of the left and right children of the parent of the current node to the parentSum variable, if they exist.
    if(root->left) parentSum += root->left->data;
    if(root->right) parentSum += root->right->data;

    // If the current node has at least one child or it's not a leaf node, set its value to the parentSum.
    if(root->left || root->right) root->data = parentSum;
}
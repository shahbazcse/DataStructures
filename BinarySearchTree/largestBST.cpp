// Link: https://practice.geeksforgeeks.org/problems/largest-bst/1

// Approach 1: Checking Valid BST + Count Nodes [TC: O(N^2) / SC: O(1)]

class Solution{
    public:
    int maxi = 1;

    bool validBST(Node* root, long min, long max){
        if(root==NULL) return true;
        
        // check whether the current node's value lies with the min-max range or not
        if(root->data <= min || root->data >= max) return false;

        // update the min-max ranges for left and right child nodes accordingly and make recursive calls them
        return validBST(root->left,min,root->data) && validBST(root->right,root->data,max);
    }

    int countNodes(Node* root){
        if(root==NULL) return 0;
        
        return countNodes(root->left) + countNodes(root->right) + 1;
    }

    int largestBst(Node *root)
    {
        if(root==NULL) return 1;
        
    	if(validBST(root,INT_MIN,INT_MAX)){
    	    maxi = max(maxi,countNodes(root));
    	}
    	
    	largestBst(root->left);
    	largestBst(root->right);
    	
    	return maxi;
    }
};

// Approach 2: Recursion + Min/Max [TC: O(N) / SC: O(N)]

// A struct to store the properties of a node in a binary tree
struct NodeValue{
    int mini;    // Minimum value in the subtree rooted at this node
    int maxi;    // Maximum value in the subtree rooted at this node
    bool isBST;  // Whether the subtree rooted at this node is a valid BST or not
    int size;    // Size of the largest BST in the subtree rooted at this node
};

// A recursive helper function to calculate the largest BST in a binary tree
NodeValue helper(Node* root, int &ans){
    // If the current node is NULL, return a NodeValue with default values
    if(root==NULL) return {INT_MAX,INT_MIN,true,0};
        
    // Recursively calculate the properties of the left and right subtrees
    NodeValue left = helper(root->left,ans);
    NodeValue right = helper(root->right,ans);
        
    // Calculate the properties of the current node based on the properties of its left and right subtrees
    NodeValue currentNode;
        
    currentNode.size = left.size + right.size + 1;  // Size of the subtree rooted at this node
        
    currentNode.mini = min(root->data,left.mini);  // Minimum value in the subtree rooted at this node
    currentNode.maxi = max(root->data,right.maxi);  // Maximum value in the subtree rooted at this node
        
    // Check if the subtree rooted at this node is a valid BST
    currentNode.isBST = ((root->data > left.maxi && root->data < right.mini) && left.isBST && right.isBST);
        
    // If the subtree rooted at this node is a valid BST, update the answer with its size
    if(currentNode.isBST) ans = max(ans,currentNode.size);
        
    // Return the properties of the subtree rooted at this node
    return currentNode;
}
    
// A class that contains the function to calculate the largest BST in a binary tree
class Solution{
    public:
    int largestBst(Node *root)
    {
        int ans = 0;
        NodeValue temp = helper(root,ans);
        return ans;
    }
};

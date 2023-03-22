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

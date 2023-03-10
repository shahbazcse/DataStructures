// Link: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal

// Approach: Recursion + Map [TC: O(NLogN) / SC: O(N)]

class Solution {
public:
    TreeNode* construct(vector<int> preorder, int preStart, int preEnd, 
                        vector<int> inorder, int inStart, int inEnd, map<int,int> &inMap)
    {
        // Base case: if either the preorder or inorder traversal is empty, return NULL
        if(preStart > preEnd || inStart > inEnd) return NULL;
        
        // Create a new node for the root of the current subtree using the first element in the preorder traversal
        TreeNode* root = new TreeNode(preorder[preStart]);

        // Find the index of the root value in the inorder traversal using the inMap map
        int inRoot = inMap[root->val];

        // Calculate the number of nodes in the left subtree (i.e., the number of nodes to the left of the root in the inorder traversal)
        int numLeft = inRoot - inStart;

        // Recursively construct the left subtree using the appropriate portions of the preorder and inorder traversal arrays
        root->left = construct(preorder, preStart+1, preStart+numLeft, inorder, inStart, inRoot-1, inMap);

        // Recursively construct the right subtree using the appropriate portions of the preorder and inorder traversal arrays
        root->right = construct(preorder, preStart+numLeft+1, preEnd, inorder, inRoot+1, inEnd, inMap);

        // Return the root node of the current subtree
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Create a map that maps each value in the inorder traversal to its index
        map<int,int> inMap;

        for(int i=0; i<inorder.size(); i++){
            inMap[inorder[i]] = i;
        }

        // Recursively construct the tree using the construct function and the entire preorder and inorder traversal arrays
        TreeNode* root = construct(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, inMap);

        // Return the root node of the tree
        return root;
    }
};
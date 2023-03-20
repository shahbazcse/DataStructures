// Link: https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

// Approach 1: Recursion + Using Preorder and Inorder [TC: O(NLogN) / SC: O(N)]

class Solution {
public:
    TreeNode* construct(vector<int> preorder, int preStart, int preEnd, 
                        vector<int> inorder, int inStart, int inEnd, map<int,int> inMap)
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

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder = preorder;

        // inorder traversal is always sorted in a BST
        sort(inorder.begin(),inorder.end());

        map<int,int> inMap;
        for(int i=0; i<inorder.size(); i++){
            inMap[inorder[i]] = i;
        }

        TreeNode* root = construct(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, inMap);

        return root;
    }
};

// Approach 2: Recursion [TC: O(N) / SC: O(N)]

class Solution {
public:
    TreeNode* construct(vector<int> &preorder, int max, int &idx){
        // if no more nodes are present in preorder or if nodes are greater than max bound of the subtree, then return NULL
        if(idx == preorder.size() || preorder[idx] > max) return NULL;
        
        // create new node if it can be placed in the subtree under the max bound
        TreeNode* root = new TreeNode(preorder[idx++]);

        // make recursive call for left subtree with value of current node as max bound
        root->left = construct(preorder,root->val,idx);
        // make recursive call for right subtree with the same INT_MAX max bound as there could exist any greater node in the right subtree
        root->right = construct(preorder,max,idx);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder){
        // max bound to place (smaller < max) values in left subtree and (smaller > max) in right subtree to construct a BST
        int max = INT_MAX;

        // keep track of preorder traversal
        int idx = 0;
        
        return construct(preorder,max,idx);
    }
};
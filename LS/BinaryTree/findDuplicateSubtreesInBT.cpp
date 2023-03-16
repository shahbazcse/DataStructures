// Link: https://leetcode.com/problems/find-duplicate-subtrees/

// Approach: Recursion + Hashing + String [TC: O(N) / SC: O(N)]

class Solution {
public:
    string helper(TreeNode* root, vector<TreeNode*> &ans, map<string,int> &mpp){
        // if nodes are NULL or leaf nodes' child
        if(root==NULL) return "null";

        // make recursive calls and generate postorder traversal of the current subtree
        string str = helper(root->left,ans,mpp)+','+helper(root->right,ans,mpp)+','+to_string(root->val);

        // hash postorder traversal using map mpp
        mpp[str]++;

        // if again the same postorder traversal is generated for the current subtree, count will become 2, so there exists a duplicate of the subtree, hence store the subtree nodes
        if(mpp[str]==2) ans.push_back(root);

        // return postorder traversal of the subtree to generate postorder traversal for the entire tree
        return str;
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        // store list of duplicate subtress
        vector<TreeNode*> ans;

        // hashing subtree nodes and it's frequency
        map<string,int> mpp;

        helper(root,ans,mpp);
        
        return ans;
    }
};
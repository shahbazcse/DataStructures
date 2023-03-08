// Link: https://leetcode.com/problems/symmetric-tree/

// Approach: Recursion [TC: O(N) / SC: O(N)]

class Solution {
public:
    bool check(TreeNode* root1, TreeNode* root2){
        // if either of nodes become NULL, the other nodes will become NULL too if they are mirror nodes, check and return true or false
        if(root1==NULL || root2==NULL) return root1==root2;

        // check if current nodes are mirror nodes to each other and are equal, if not, return false
        if(root1->val != root2->val) return false;

        // make recursive calls for left and right child nodes, the movement will be opposite, if root1 is moving left then root2 must move right, depicting the mirror movement
        return check(root1->left,root2->right) && check(root1->right,root2->left);
    }
    bool isSymmetric(TreeNode* root){
        // pass left and right subtrees' roots to check if their nodes behave like mirror nodes
        return root==NULL || check(root->left,root->right);
    }
};
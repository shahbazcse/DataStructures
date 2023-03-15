// Link: https://leetcode.com/problems/check-completeness-of-a-binary-tree/description/

// Approach 1: BFS + Queue [TC: O(N) / SC: O(N)]

class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        if(root==NULL) return false;

        queue<TreeNode*> q;
        q.push(root);

        /* 
            If we ever find any node after the gotNullSoFar becomes True, then it is not a 
            complete tree as there is an absent left child node in the last level which
            changes the gotNullSoFar to True, and a right child node is present after it
        */
        bool gotNullSoFar = false;

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            // first NULL child node found, so there must not exist any nodes further
            if(node==NULL){
                gotNullSoFar=true;
            }else{
                // if any node exists after we have got a NULL child node in the past, then it is not a complete tree
                if(gotNullSoFar==true) return false;
                q.push(node->left);
                q.push(node->right);
            }
        }
        return true;
    }
};

// Approach 2: DFS + Recursion [TC: O(N) / SC: O(N)]

class Solution {
public:
    // dfs traversal
    bool helper(TreeNode* node, int count, int i){
        // if node is NULL, then it is leaf node's child and leaf node is included in total nodes count, so return true
        if(node==NULL) return true; // complete tree

        /* 
            We have indexed the entire tree including the NULL child node's place, 
            so if index becomes greater than or equal to total nodes count, 
            then there exists a missing left child's place which was indexed but not counted 
            as it was a NULL node, so return false
        */
        if(i>=count) return false; // not a complete tree

        // recursive calls for traversing to left and right child nodes
        return helper(node->left,count,2*i+1) && helper(node->right,count,2*i+2);
    }
    
    // count total nodes in the binary tree
    int countNodes(TreeNode* node){
        if(node==NULL) return 0;

        return countNodes(node->left) + countNodes(node->right) + 1;
    }

    bool isCompleteTree(TreeNode* root) {
        int count = countNodes(root);
        return helper(root,count,0);
    }
};
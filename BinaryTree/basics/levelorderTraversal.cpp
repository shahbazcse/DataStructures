// Link: https://leetcode.com/problems/binary-tree-level-order-traversal

// Approach 1: Iterative + Queue [TC: O(N) / SC: O(N)]

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        // initialize a vector of vectors to store the answer
        vector<vector<int>> ans; 
        
        // if root is NULL, return an empty answer vector
        if(root==NULL) return ans; 
        
        // initialize a queue of TreeNodes
        queue<TreeNode*> q; 
        
        // add root to the queue
        q.push(root); 

        // while the queue is not empty
        while(!q.empty()){ 
            // initialize a vector to store the nodes in the current level
            vector<int> level;  

            // get the number of nodes in the current level
            int nodeCount = q.size(); 

            // store all nodes in the current level in 'level' vector
            for(int i=0; i<nodeCount; i++){ 
                // get the front node in the queue
                TreeNode* front = q.front(); 
                
                // remove the front node from the queue
                q.pop(); 

                // add the left child to the queue if it exists
                if(front->left!=NULL) q.push(front->left);  
                
                // add the right child to the queue if it exists
                if(front->right!=NULL) q.push(front->right); 
                
                // push the front node's value to the level vector
                level.push_back(front->val);  
            }

            // add the level vector to the answer vector
            ans.push_back(level);  
        }
        return ans;
    }
};

// Approach 2: Recursion [TC: O(N) / SC: O(N)]

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root, vector<vector<int>> &ans, int level){
        if(root==NULL) return;

        // if level has not been traversed before, add a new empty vector
        if(level==ans.size()) ans.push_back({});

        // push node's value in the level
        ans[level].push_back(root->val);

        // recursive calls for left and right child nodes
        solve(root->left,ans,level+1);
        solve(root->right,ans,level+1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        
        solve(root,ans,0);

        return ans;
    }
};
// Link: https://leetcode.com/problems/binary-tree-level-order-traversal-ii/description/

// Approach 1: Iterative BFS + Queue + Reverse [TC: O(N) / SC: O(N)]

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int nodesCount = q.size();
            vector<int> ds;

            while(nodesCount--){
                TreeNode* node = q.front();
                q.pop();

                ds.push_back(node->val);

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            ans.push_back(ds);
        }
        reverse(ans.begin(),ans.end()); // reverse the ans list to get bottom-up level order traversal

        return ans;
    }
};

// Approach 2: Iterative BFS + Queue + Insert At Front [TC: O(N) / SC: O(N)]

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int nodesCount = q.size();
            vector<int> ds;

            while(nodesCount--){
                TreeNode* node = q.front();
                q.pop();

                ds.push_back(node->val);

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            ans.insert(ans.begin(),ds); // insert from front of ans to get bottom-up level order traversal
        }

        return ans;
    }
};
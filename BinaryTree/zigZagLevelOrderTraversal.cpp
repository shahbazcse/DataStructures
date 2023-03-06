// Link: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

// Approach 1: Iterative + Queue [TC: O(N) / SC: O(N)]

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;

        queue<TreeNode*> q;
        q.push(root);

        int k=0;

        while(!q.empty()){
            vector<int> level;
            int nodeCount = q.size();

            while(nodeCount--){
                TreeNode* front = q.front();
                q.pop();
                level.push_back(front->val);

                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }

            k++;
            
            if(k%2==0) reverse(level.begin(),level.end());
            ans.push_back(level);
        }
        return ans;
    }
};

// Approach 2: Recursion [TC: O(N) / SC: O(N)]

class Solution {
public:
    void solve(TreeNode* root, vector<vector<int>> &ans, int level){
        if(root==NULL) return;

        if(level==ans.size()) ans.push_back({});

        if(level%2!=0) ans[level].insert(ans[level].begin(),root->val);
        if(level%2==0) ans[level].push_back(root->val);

        solve(root->left,ans,level+1);
        solve(root->right,ans,level+1);
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        solve(root,ans,0);
        return ans;
    }
};
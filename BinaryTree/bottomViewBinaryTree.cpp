// Link: https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1

// Approach: Iterative + Map + Queue [TC: O(NLogN) / SC: O(N)]

class Solution {
  public:
    vector <int> bottomView(Node *root) {
        vector<int> ans;
        if(root==NULL) return ans;
        
        map<int,int> mpp;
        
        queue<pair<Node*,int>> q;
        q.push({root,0});
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            
            Node* node = it.first;
            
            int col = it.second;
            
            mpp[col] = node->data;
            
            if(node->left) q.push({node->left,col-1});
            if(node->right) q.push({node->right,col+1});
        }
        
        for(auto it : mpp){
            ans.push_back(it.second);
        }
        return ans;
    }
};
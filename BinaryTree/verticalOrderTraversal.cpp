// Link: https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

// Approach: Iterative + Queue + Map + Multiset [TC: O(NLogN) / SC: O(N)]

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // Create a map to store nodes based on their x and y coordinates
        // Use multiset to store multiple nodes with the same (x, y) coordinates
        map<int, map<int, multiset<int>>> nodes;
        
        // Create a queue to perform breadth-first search of the binary tree
        // Each node in the queue is associated with its (x, y) coordinates
        queue<pair<TreeNode*, pair<int,int>>> todo;
        todo.push({root,{0,0}});

        // Traverse the binary tree and store nodes in the map container
        while(!todo.empty()){
            auto p = todo.front();
            todo.pop();

            // extract node from p
            TreeNode* node = p.first;

            // extract coordinates from p
            int x = p.second.first, y = p.second.second;
            nodes[x][y].insert(node->val);

            // Add the left and right child nodes to the queue along with their (x, y) coordinates
            if(node->left) todo.push({node->left,{x-1,y+1}});
            if(node->right) todo.push({node->right,{x+1,y+1}});
        }

        // Retrieve the values of nodes from each column of the map and add them to the answer vector
        vector<vector<int>> ans;
        for(auto p : nodes){
            vector<int> col;
            for(auto q : p.second){
                col.insert(col.end(),q.second.begin(),q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};
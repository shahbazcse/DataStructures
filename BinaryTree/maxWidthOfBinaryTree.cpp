// Link: https://leetcode.com/problems/maximum-width-of-binary-tree/

// Approach: Iterative BFS [TC: O(N) / SC: O(N)]

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        // If the root is null, the tree is empty and has zero width.
        if(root==NULL) return 0;

        int ans=0;

        // Create a queue to store pairs of nodes and their indices.
        queue<pair<TreeNode*,int>> q;

        // Push the root node with index 0 to the queue.
        q.push({root,0});

        // Traverse the tree level by level using the queue.
        while(!q.empty()){
            // Get the number of nodes in the current level.
            int size = q.size();

            // Get the index of the first node in the current level.
            int mmin = q.front().second;

            // Define variables to keep track of the first and last indices in the current level.
            int first, last;

            // Loop through all the nodes in the current level.
            for(int i=0; i<size; i++){
                // Calculate the current index of the node by subtracting the minimum index of the level.
                long idx = q.front().second-mmin;

                // Get the node at the front of the queue and remove it from the queue.
                TreeNode* node = q.front().first;
                q.pop();

                // Update the value of 'first' if this is the first node in the level.
                if(i==0) first = idx;
                
                // Update the value of 'last' if this is the last node in the level.
                if(i==size-1) last = idx;

                // Push the left and right children of the current node to the queue if they exist.
                if(node->left) q.push({node->left,idx*2+1});
                if(node->right) q.push({node->right,idx*2+2});
            }
            // Update the maximum width of the tree by taking the difference between 'last' and 'first' plus one.
            ans = max(ans,last-first+1);
        }
        // Return the maximum width of the tree.
        return ans;
    }
};